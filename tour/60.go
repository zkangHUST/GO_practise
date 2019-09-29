//  接口
//  接口类型 是由一组方法签名定义的集合。

//  接口类型的变量可以保存任何实现了这些方法的值。

//  注意: 示例代码的 22 行存在一个错误。由于 Abs 方法只为 *Vertex （指针类型）定义，因此 Vertex（值类型）并未实现 Abser。

package main

import (
	"fmt"
	"math"
)

func main() {
	var aa Abser
	var a MyFloat = 45.0
	p := Vertex{3, 4}
	aa = &p
	fmt.Println(aa.Abs())
	aa = &p
	fmt.Println(aa.Abs())
	aa = p			// ERROR, Vertex does not implement Abser (Abs method has pointer receiver)
	fmt.Println(aa.Abs())
}

type Abser interface {
	Abs() float64
}

type MyFloat float64

type Vertex struct {
	x, y float64
}

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.x * v.x + v.y * v.y)
}

// func (v Vertex) Abs() float64 {
// 	return math.Sqrt(v.x * v.x + v.y * v.y)
// }

