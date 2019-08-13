package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	counts := make(map[string]int)
	inputScanner := bufio.NewScanner(os.Stdin)

	for inputScanner.Scan() {
		counts[inputScanner.Text()]++
	}

	for key, value := range counts {
		if value > 1 {
			fmt.Printf("%s %3d\n", key, value)
		} else {
			fmt.Printf("%s\n", key);
		}
	}
}