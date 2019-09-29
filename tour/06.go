// go 函数可以返回任意数量的返回值
package main

import (
	"fmt"
)

func main() {
	a, b := swap("vincent", "I love you")
	fmt.Println(a, b)
}

func swap(x, y string) (string, string) {
	return y, x
}