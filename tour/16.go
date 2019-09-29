// 数值常量
// 数值常量是高精度的 值。

// 一个未指定类型的常量由上下文来决定其类型。

// 再尝试一下输出 needInt(Big) 吧。

// （int 类型最大可以存储一个 64 位的整数，有时会更小。）

// （int 可以存放最大64位的整数，根据平台不同有时会更少。

package main

import (
	"fmt"
)

const (
	Big = 1 << 100
	Small = Big >> 99
)

func main()  {
	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))
}

func needInt(x int) int {return x * 10 + 1}
func needFloat(x float64) float64 {
	return x * 0.1
}