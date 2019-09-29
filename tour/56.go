
// 练习：斐波纳契闭包
// 让我们用函数做些好玩的事情。

// 实现一个 fibonacci 函数，它返回一个函数（闭包），该闭包返回一个斐波纳契数列 `(0, 1, 1, 2, 3, 5, ...)`。
package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
	a := 1
	b := 0
	return func()int {
		tmp := b
		b, a = a, a + b
		return tmp
	}
	
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
