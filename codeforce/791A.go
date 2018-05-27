package main

import "fmt"

func main() {
	var l, b int
	fmt.Scan(&l, &b)
	var year = 0
	for l <= b {
		l *= 3
		b *= 2
		year++
	}
	fmt.Print(year)
}
