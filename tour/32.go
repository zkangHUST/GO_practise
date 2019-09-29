// 结构体指针
// 结构体字段可以通过结构体指针来访问。

// 如果我们有一个指向结构体的指针 p，那么可以通过 (*p).X 来访问其字段 X。不过这么写太啰嗦了，所以语言也允许我们使用隐式间接引用，直接写 p.X 就可以。

package main

import (
	"fmt"
)
type Vertex struct {
	x int
	y int
}

func main()  {
	V := Vertex{1, 2}
	p := &V
	p.x = 1e9
	p.y = 20
	fmt.Println(*p)	
}