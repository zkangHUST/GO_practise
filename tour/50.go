
// 映射的文法
// 映射的文法与结构体相似，不过必须有键名。

package main

import "fmt"

type Vertex struct {
	x int
	y int
}

var x = map[string]Vertex {
	"vincent":Vertex{100, 100},
	"erli":Vertex{200, 200},
}

func main()  {
	fmt.Println(x)
}