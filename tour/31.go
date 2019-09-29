// 结构体
// 一个结构体（struct）就是一组字段（field）。
// 结构体字段使用点号来访问。

package main

import (
	"fmt"
)


type Vertex struct {
	X int
	Y int
	Z int
}

func main() {
	v := Vertex{1, 2, 3}
	v.X = 4
	fmt.Println(v)
}