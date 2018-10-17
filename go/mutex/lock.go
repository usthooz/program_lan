package main

import (
	"sync"
	"time"

	"github.com/usthooz/oozlog/go"
)

func main() {
	mutexLock()
}

/*
	output:
	2018/10/17 10:12:14 [INFO] Lock 0. [lock.go:18]
	2018/10/17 10:12:14 [INFO] Locked 0. [lock.go:21]
	2018/10/17 10:12:14 [INFO] Lock 3. [lock.go:24]
	2018/10/17 10:12:14 [INFO] Lock 2. [lock.go:24]
	2018/10/17 10:12:14 [INFO] Lock 1. [lock.go:24]
	2018/10/17 10:12:15 [INFO] Unlock 0. [lock.go:30]
	2018/10/17 10:12:15 [INFO] Unlocked 0. [lock.go:32]
*/
func mutexLock() {
	var (
		lock sync.Mutex
	)
	ozlog.Infof("Lock 0.")
	// 上锁
	lock.Lock()
	ozlog.Infof("Locked 0.")
	for i := 1; i <= 3; i++ {
		go func(i int) {
			ozlog.Infof("Lock %d.", i)
			lock.Lock()
			ozlog.Infof("Locked %d.", i)
		}(i)
	}
	time.Sleep(time.Second)
	ozlog.Infof("Unlock 0.")
	defer lock.Unlock()
	ozlog.Infof("Unlocked 0.")
}
