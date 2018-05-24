package main

import "fmt"

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)
	var a, d int
	for i := 0; i < n; i++ {
		r := s[i]
		if r == 'A' {
			a++
		} else if r == 'D' {
			d++
		}
	}
	if a > d {
		fmt.Print("Anton")
	} else if a < d {
		fmt.Print("Danik")
	} else {
		fmt.Print("Friendship")
	}
}
