package sorttest

import "fmt"

/*
	Name: 选择排序
	Desc: 每一次从待排序的数据元素中选出最小（或最大）的一个元素，
	存放在序列的起始位置，循环比对数据的大小，进行数据位置的交换，
	直到全部待排序的数据元素排完。
*/

func SelectionSort(nums []int32) {
	length := len(nums)
	for i := 0; i < length; i++ {
		min := i
		for j := i + 1; j < length; j++ {
			if nums[j] < nums[min] {
				min = j
			}
		}
		temp := nums[i]
		nums[i] = nums[min]
		nums[min] = temp
	}
	fmt.Println(nums)
}

/*
	Name: 冒泡排序
	Desc:
*/
