package main

import (
	"bytes"
	"html/template"
	"log"
	"time"

	"github.com/vanng822/go-premailer/premailer"
	mail "github.com/xhit/go-simple-mail/v2"
)

type Mail struct {
	Domain      string
	Host        string
	Port        int
	Username    string
	Password    string
	Encryption  string
	FromAddress string
	FromName    string
}

type File struct {
	Name   string
	Base64 string
}

type Message struct {
	From        string
	FromName    string
	To          string
	Cc          string
	Subject     string
	Attachments []string
	Data        any
	Name        string
	Email       string
	Package     string
	File        File
	DataMap     map[string]any
}

func (m *Mail) SendSMTPMessage(msg Message) error {
	if msg.From == "" {
		msg.From = m.FromAddress
	}

	if msg.FromName == "" {
		msg.FromName = m.FromName
	}

	data := map[string]any{
		"message": msg.Data,
		"name":    msg.Name,
		"email":   msg.Email,
		"package": msg.Package,
		"subject": msg.Subject,
		"file":    msg.File,
	}

	msg.DataMap = data

	formattedMessage, err := m.buildHTMLMessage(msg)
	if err != nil {
		return err
	}

	// plainMessage, err := m.buildPlainTextMessage(msg)
	// if err != nil {
	// 	return err
	// }

	server := mail.NewSMTPClient()
	server.Host = m.Host
	server.Port = m.Port
	server.Username = m.Username
	server.Password = m.Password
	server.Encryption = m.getEncryption(m.Encryption)
	server.KeepAlive = false
	server.ConnectTimeout = 10 * time.Second
	server.SendTimeout = 10 * time.Second

	smtpClient, err := server.Connect()
	if err != nil {
		log.Println(err)
		return err
	}

	email := mail.NewMSG()
	email.SetFrom(msg.From).
		AddTo(msg.To).
		AddCc(msg.Cc).
		SetSubject(msg.Subject)

	email.SetBody(mail.TextHTML, formattedMessage)
	// email.AddAlternative(mail.TextHTML, formattedMessage)

	if len(msg.Attachments) > 0 {
		for _, x := range msg.Attachments {
			email.AddAttachment(x)
		}
	}
	//Attach a file with path
	// email.Attach(&mail.File{FilePath: "./gomailer.png"})
	if len(msg.File.Base64) > 0 {
		email.Attach(&mail.File{B64Data: msg.File.Base64, Name: msg.File.Name})
	}

	err = email.Send(smtpClient)
	if err != nil {
		log.Println(err)
		return err
	}

	return nil
}

func (m *Mail) buildHTMLMessage(msg Message) (string, error) {
	templateToRender := "./templates/mailTest.html.gohtml"

	t, err := template.New("email-html").ParseFiles(templateToRender)
	if err != nil {
		return "", err
	}

	var tpl bytes.Buffer
	if err = t.ExecuteTemplate(&tpl, "body", msg.DataMap); err != nil {
		return "", err
	}

	formattedMessage := tpl.String()
	formattedMessage, err = m.inlineCSS(formattedMessage)
	if err != nil {
		return "", err
	}

	return formattedMessage, nil
}

// func (m *Mail) buildPlainTextMessage(msg Message) (string, error) {
// 	templateToRender := "./templates/mail.plain.gohtml"

// 	t, err := template.New("email-plain").ParseFiles(templateToRender)
// 	if err != nil {
// 		return "", err
// 	}

// 	var tpl bytes.Buffer
// 	if err = t.ExecuteTemplate(&tpl, "body", msg.DataMap); err != nil {
// 		return "", err
// 	}

// 	plainMessage := tpl.String()

// 	return plainMessage, nil
// }

func (m *Mail) inlineCSS(s string) (string, error) {
	options := premailer.Options{
		RemoveClasses:     false,
		CssToAttributes:   false,
		KeepBangImportant: true,
	}

	prem, err := premailer.NewPremailerFromString(s, &options)
	if err != nil {
		return "", err
	}

	html, err := prem.Transform()
	if err != nil {
		return "", err
	}

	return html, nil
}

func (m *Mail) getEncryption(s string) mail.Encryption {
	switch s {
	case "tls":
		return mail.EncryptionSTARTTLS
	case "ssl":
		return mail.EncryptionSSLTLS
	case "none", "":
		return mail.EncryptionNone
	default:
		return mail.EncryptionSTARTTLS
	}
}
