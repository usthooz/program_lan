package main

import "fmt"

var (
	dlist map[int]int
)

func init() {
	dlist = make(map[int]int)
}

func main() {
	f1()
	for k, v := range dlist {
		fmt.Printf("k: %d, v: %d\n", k, v)
		delete(dlist, k)
	}
}

func f1() {
	for i := 0; i < 10; i++ {
		f2(i)
	}
	for k, _ := range dlist {
		dlist[k] += 1
	}
}

func f2(i int) {
	if i%2 == 0 {
		dlist[i] = i
	}
}
