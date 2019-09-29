// defer
// defer 语句会将函数推迟到外层函数返回之后执行。

// 推迟调用的函数其参数会立即求值，但直到外层函数返回前该函数都不会被调用。
package main

import "fmt"

func main() {
	x := 1
	x++
	defer fmt.Println(x)
	x++
	fmt.Println(x)
}
