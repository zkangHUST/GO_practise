
// 映射的文法（续）
// 若顶级类型只是一个类型名，你可以在文法的元素中省略它。

package main

import (
	"fmt"
)

type Vertex struct {
	x, y int
}
var m = map[string]Vertex {
	"vincent": {750, 750},
	"erli": {750, 750},
}

func main() {
	fmt.Println(m)	
}