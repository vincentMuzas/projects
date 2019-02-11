package main

import (
	"bufio"
	"fmt"
	"net"
	"time"
)

func listen() {
	ln, err := net.Listen("tcp", ":9001")
	if err != nil {
		// handle error
	}
	for {
		conn, err := ln.Accept()
		if err != nil {
			fmt.Println(err)
			// handle error
		}
		fmt.Println(conn)
	}
}

func main() {
	go listen()
	time.Sleep(time.Second)
	conn, err := net.Dial("tcp", "127.0.0.1:9001")
	if err != nil {
		fmt.Println(err)
		return
		// handle error
	}
	status, err := bufio.NewReader(conn).ReadString('\n')
	fmt.Println(status, err)
	str := []byte("bonjour")
	conn.Write(str)
	return
}
