package main

import "fmt"

func main() {
	var k, r int
	fmt.Scan(&k, &r)
	var cnt = 1
	var remain = k % 10
	for remain != r && remain != 0 {
		remain = (k + remain) % 10
		cnt++
	}
	fmt.Print(cnt)
}
