package main

import (
	"fmt"
)

func main()  {
	fmt.Println(add(10, 20))
}

func add(x, y int) int  {
	return x + y
}