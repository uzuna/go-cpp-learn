FROM golang:1.12.4

WORKDIR /app

COPY . .


RUN make howto-go-with-cpp
