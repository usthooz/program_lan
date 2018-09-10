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
			// 如果无缓冲通道则等待接收方接收完成才继续写入，否则阻塞在此处
			// 有缓冲通道则持续写入至缓冲已满，等到接收方读取后有空位，则继续写入
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
