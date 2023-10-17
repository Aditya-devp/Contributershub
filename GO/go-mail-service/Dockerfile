# Use the official Golang image as the base image
FROM golang:1.20-alpine AS build

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Build the Go application
RUN go build -o go-mail-service .

# Use a smaller base image for the final image
FROM alpine:3.18.2

COPY --from=build /app/templates /templates
# Copy the binary from the build image
COPY --from=build /app/go-mail-service /usr/local/bin/go-mail-service

EXPOSE 3200
# Set the entrypoint for the container
ENTRYPOINT ["go-mail-service"]
