// 向切片追加元素
// 为切片追加新的元素是种常用的操作，为此 Go 提供了内建的 append 函数。内建函数的文档对此函数有详细的介绍。

// func append(s []T, vs ...T) []T
// append 的第一个参数 s 是一个元素类型为 T 的切片，其余类型为 T 的值将会追加到该切片的末尾。

// append 的结果是一个包含原切片所有元素加上新添加元素的切片。

// 当 s 的底层数组太小，不足以容纳所有给定的值时，它就会分配一个更大的数组。返回的切片会指向这个新分配的数组。

// （要了解关于切片的更多内容，请阅读文章 Go 切片：用法和本质。）

package main

import (
	"fmt"
)

func main() {
	var s[]int
	printSlice(s)

	s = append(s, 1)
	printSlice(s)

	s = append(s, 1, 2, 3, 4)
	printSlice(s)

	s = append(s, 7)
	printSlice(s)

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
