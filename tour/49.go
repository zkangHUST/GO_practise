// 映射
// 映射将键映射到值。

// 映射的零值为 nil 。nil 映射既没有键，也不能添加键。

// make 函数会返回给定类型的映射，并将其初始化备用。

package main

import (
	"fmt"
)

type Vertex struct {
	x int
	y int
}
var m map[string]Vertex

func main() {
	m = make(map[string]Vertex)
	m["vincent"] = Vertex{100,100}
	fmt.Println(m["vincent"])
}