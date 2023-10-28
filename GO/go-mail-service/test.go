package main

import (
	"crypto/tls"
	"log"
	"time"

	mail "github.com/xhit/go-simple-mail/v2"
)

const htmlBody = `<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>Hello Gophers!</title>
	</head>
	<body>
		<p>This is the <b>Go gopher</b>.</p>
		<p><img src="cid:Gopher.png" alt="Go gopher" /></p>
	</body>
</html>`

func Test() {
	server := mail.NewSMTPClient()

	// SMTP Server
	server.Host = "smtp.gmail.com"
	server.Port = 587
	server.Username = "email@example.com"
	server.Password = "secret"
	server.Encryption = mail.EncryptionSTARTTLS

	// Variable to keep alive connection
	server.KeepAlive = false

	// Timeout for connect to SMTP Server
	server.ConnectTimeout = 10 * time.Second

	// Timeout for send the data and wait respond
	server.SendTimeout = 10 * time.Second

	// Set TLSConfig to provide custom TLS configuration. For example,
	// to skip TLS verification (useful for testing):
	server.TLSConfig = &tls.Config{InsecureSkipVerify: true}

	// SMTP client
	smtpClient, err := server.Connect()

	if err != nil {
		log.Fatal(err)
	}

	// New email simple html with inline and CC
	email := mail.NewMSG()
	email.SetFrom("From Gopher <email@example.com>").
		AddTo("email@example.com").
		// AddCc("otherto@example.com").
		SetSubject("New Go Email").
		SetListUnsubscribe("<mailto:unsubscribe@example.com?subject=https://example.com/unsubscribe>")

	// email.SetBody(mail.TextHTML, htmlBody)
	// htmlBody := "./templates/mail.html.gohtml"
	// also you can add body from []byte with SetBodyData, example:
	email.SetBodyData(mail.TextHTML, []byte(htmlBody))
	// or alternative part
	// email.AddAlternativeData(mail.TextHTML, []byte(htmlBody))

	// add inline
	email.Attach(&mail.File{FilePath: "./gomailer.png", Name: "Gopher.png", Inline: true})

	// always check error after send
	if email.Error != nil {
		log.Fatal(email.Error)
	}

	// Call Send and pass the client
	err = email.Send(smtpClient)
	if err != nil {
		log.Println(err)
	} else {
		log.Println("Email Sent")
	}
}
