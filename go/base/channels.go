package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	ch = make(chan int64, 5)
)

func main() {
	var (
		wg sync.WaitGroup
	)
	go func() {
		for {
			ts := time.Now().Unix()
			ch <- ts
			fmt.Println("send:", ts)
			time.Sleep(time.Duration(1) * time.Second)
		}
		wg.Done()
	}()
	wg.Add(1)

	go func() {
		for {
			res, ok := <-ch
			if !ok {
				break
			}
			fmt.Println("recv:", res)
			time.Sleep(time.Duration(5) * time.Second)
		}
		wg.Done()
	}()
	wg.Add(1)
	wg.Wait()
}
