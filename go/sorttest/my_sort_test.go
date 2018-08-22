package sorttest

import (
	"math/rand"
	"testing"
	"time"
)

func TestSelectionSort(t *testing.T) {
	var (
		nums []int32
		len  int = 100
	)
	for i := 0; i < len; i++ {
		// 随机数
		rand.Seed(time.Now().UnixNano())
		nums = append(nums, rand.Int31())
	}
	ti := time.Now()
	SelectionSort(nums)
	t.Logf("Selection Sort: %dms", time.Since(ti).Nanoseconds()/1000)
}
