package main

import (
	"fmt"
	"time"
)

type hehe struct {
	laBalaine int
	leLion    string
}

func yolol() (int, int) {
	return 1, 2
}

func mygroutine() {
	i := 0

	for i < 50 {
		fmt.Println(i)
		i++
		time.Sleep(1000 * time.Millisecond)
	}
}

func main() {
	i, str := 0, "je test"

	for i < 10 {
		fmt.Println(str, i+1)
		i++
	}
	p := fmt.Println
	date := time.Now
	p(date)

	a, b := yolol()
	fmt.Println(a, b)

	var animal hehe
	animal.laBalaine = 1
	animal.leLion = "roar"
	fmt.Println(animal)
	go mygroutine()
	time.Sleep(1 * time.Second)
	go mygroutine()
	var input string
	fmt.Scanln(&input)
	fmt.Println("done")
}
