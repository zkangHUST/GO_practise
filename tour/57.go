// 方法
// Go 没有类。不过你可以为结构体类型定义方法。

// 方法就是一类带特殊的 接收者 参数的函数。

// 方法接收者在它自己的参数列表内，位于 func 关键字和方法名之间。

// 在此例中，Abs 方法拥有一个名为 v，类型为 Vertex 的接收者。
package main

import (
	"fmt"
	"math"
)

func main() {
	a := Vertex{3, 4}
	fmt.Println(a.Abs())
	fmt.Println(Abs(a))
}

type Vertex struct {
	x, y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.x * v.x + v.y * v.y)
}

func Abs(v Vertex) float64 {
	return math.Sqrt(v.x * v.x + v.y * v.y)
}	