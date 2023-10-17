package main

import (
	"log"
	"net/http"
)

func (app *Config) SendMail(w http.ResponseWriter, r *http.Request) {

	type mailMessage struct {
		From    string `json:"from"`
		To      string `json:"to"`
		Cc      string `json:"cc"`
		Subject string `json:"subject"`
		Message string `json:"message"`
		Name    string `json:"name"`
		Email   string `json:"email"`
		Package string `json:"package"`
		File    File   `json:"file"`
	}

	var requestPayload mailMessage

	err := app.readJSON(w, r, &requestPayload)
	if err != nil {
		log.Println(err)
		app.errorJSON(w, err)
		return
	}

	msg := Message{
		From:    requestPayload.From,
		To:      requestPayload.To,
		Cc:      requestPayload.Cc,
		Subject: requestPayload.Subject,
		Data:    requestPayload.Message,
		Name:    requestPayload.Name,
		Email:   requestPayload.Email,
		Package: requestPayload.Package,
		File:    requestPayload.File,
	}

	err = app.Mailer.SendSMTPMessage(msg)
	if err != nil {
		log.Println(err)
		app.errorJSON(w, err)
		return
	}

	payload := jsonResponse{
		Error:   false,
		Message: "sent to " + requestPayload.To,
	}

	app.writeJSON(w, http.StatusAccepted, payload)
}
