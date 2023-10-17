# GO Email Service

Before you can try it out set your own email credentials by adding .env file.

## Set environments with .env

```sh
# ./.env
MAIL_PORT=587
MAIL_DOMAIN=gmail.com
MAIL_HOST=smtp.gmail.com
MAIL_USERNAME=email@example.com
MAIL_PASSWORD=secret
MAIL_ENCRYPTION=tls
FROM_NAME=Gopher
FROM_ADDRESS=email@example.com
```

## Send Test Email

1. To send a test email change your email credentials inside test.go

```go
// test.go
// SMTP Server
server.Host = "smtp.gmail.com"
server.Port = 587
server.Username = "email@example.com"
server.Password = "secret"
server.Encryption = mail.EncryptionSTARTTLS
```

2. Uncomment Test() function at top of main.go

![GO Mailer](gomailer.png)
