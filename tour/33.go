// 结构体文法
// 结构体文法通过直接列出字段的值来新分配一个结构体。

// 使用 Name: 语法可以仅列出部分字段。（字段名的顺序无关。）

// 特殊的前缀 & 返回一个指向结构体的指针。

package main

import (
	"fmt"
)
 
type Vertex struct{
	x, y int
}

var (
	v1 = Vertex{1, 2}
	v2 = Vertex{x:1}  //// y:0 被隐式地赋予
	v3 = Vertex{y:2}
	v4 = Vertex{}
	p = &Vertex{3, 4}
	p1 = person{"vincent", 20}
)

func main() {
	fmt.Println(v1, v2, v3, v4, p, p1)			// {1 2} {1 0} {0 2} {0 0} &{3 4} {vincent 20}
}

type person struct {
	name string
	age int
}