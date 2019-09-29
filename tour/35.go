// 类型 [n]T 表示拥有 n 个 T 类型的值的数组。

// 表达式

// var a [10]int
// 会将变量 a 声明为拥有 10 个整数的数组。

// 数组的长度是其类型的一部分，因此数组不能改变大小。这看起来是个限制，不过没关系，Go 提供了更加便利的方式来使用数组。
package main

import (
	"fmt"
)

func main()  {	
	var names [10]string
	ages := [10]int {10, 20, 30}
	names[0] = "vincent"
	names[1] = "erli"
	fmt.Println(names[0], names[1])
	fmt.Println(names)
	fmt.Println(ages)
}
