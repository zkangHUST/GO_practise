package main

import (
	"fmt"
	"os"
	"io/ioutil"
	"bufio"
	"strings"
)

func main() {
	counts := make(map[string]int)
	files := os.Args[1:]
	
	if len(files) == 0 {
		stat(os.Stdin, counts)
	} else {
		for _, file := range files {
			data, err := ioutil.ReadFile(file)
			// fmt.Println(string(data));

			if err != nil {
				fmt.Fprintf(os.Stderr, "ReadFile:%v\n", err)
				continue
			}
			for _, line := range strings.Split(string(data), "\n") {
				counts[line]++
			}
		}
	}
	print(counts)
}

func print(counts map[string]int) {
	for key, value := range counts {
		if value > 1 {
			fmt.Printf("%s %3d\n", key, value)
		} else {
			fmt.Printf("%s\n", key);
		}
	}
}

func stat(f *os.File, counts map[string]int) {
	inputScanner := bufio.NewScanner(f)

	for inputScanner.Scan() {
		counts[inputScanner.Text()]++
	}
}