package main

import (
	"fmt"
	"gopl/tutorial/package/calc"
)

func main() {
	var a int32 = 1;
	var b int32 = 2;
	sum := calc.Add(a, b);
	diff := calc.Sub(a, b);
	fmt.Printf("%d + %d = %d\n", a, b, sum);
	fmt.Printf("%d - %d = %d\n", a, b, diff);
	fmt.Printf("%d / %d = %d\n", a, b, calc.Div(a, b));
}