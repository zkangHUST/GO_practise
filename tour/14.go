// 类型推导
// 在声明一个变量而不指定其类型时（即使用不带类型的 := 语法或 var = 表达式语法），变量的类型由右值推导得出。

// 当右值声明了类型时，新变量的类型与其相同：

// var i int
// j := i // j 也是一个 int
// 不过当右边包含未指明类型的数值常量时，新变量的类型就可能是 int, float64 或 complex128 了，这取决于常量的精度：

// i := 42           // int
// f := 3.142        // float64
// g := 0.867 + 0.5i // complex128
// 尝试修改示例代码中 v 的初始值，并观察它是如何影响类型的。

package main

import (
	"fmt"
)

func main()  {
	a := 42  // int 
	b := 42.0 // float64
	c := b	// float64
	d := 0.867 + 0.5i // complex128

	fmt.Printf("type: %T, value: %v\n", a, a)
	fmt.Printf("type: %T, value: %v\n", b, b)
	fmt.Printf("type: %T, value: %v\n", c, c)
	fmt.Printf("type: %T, value: %v\n", d, d)
}