package main

import (
	"fmt"
	"sync"
)

func main() {
	var (
		wg sync.WaitGroup
	)
	c := make(chan int, 3)
	for i := 1; i < 4; i++ {
		wg.Add(1)
		go func(i int) {
			for j := 1; j < 4; j++ {
				if j == i {
					c <- i
					break
				}
			}
			wg.Done()
		}(i)
	}
	wg.Wait()
	close(c)
	for a := range c {
		fmt.Println(a)
	}
}
