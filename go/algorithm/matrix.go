package main

import (
	"github.com/usthooz/oozlog/go"
)

const (
	row int = 5
	col int = 5
)

var (
	matrix = [col][row]string{
		{"H", "T", "Q", "Z", "A"},
		{"F", "E", "O", "H", "P"},
		{"O", "M", "L", "M", "B"},
		{"C", "S", "O", "L", "Q"},
		{"H", "X", "D", "K", "O"},
	}
)

func main() {
	// invalid
	if col != row || col%2 == 0 {
		return
	}
	words := chapter1()
	ozlog.Infof("%v", words)
}

// When words lie on either straight line in 8 directions(horizontal, vertical or diagonal)，get all words.
// chapter1->logn
func chapter1() []string {
	var (
		words []string
		// 正对角线
		s1, s2, s3, s4, s5, s6, s7, s8 string
	)
	rowIndex := row/2 + row%2 - 1
	colIndex := col/2 + col%2 - 1
	for i := 0; i < col; i++ {
		for j := 0; j < row; j++ {
			/*
				i==j 正对角
				i+j == row -1 反对角

				i == 0 第一行
				j == 0 第一列
				j == row-1 最后一列
				i == col-1 最后一行

				j == rowIndex 中间列
				i == colIndex 中间行
			*/
			if i == j {
				s1 += matrix[i][j]
			}
			if i+j == row-1 {
				s2 += matrix[i][j]
			}
			if i == 0 {
				s3 += matrix[i][j]
			}
			if j == 0 {
				s4 += matrix[i][j]
			}
			if j == row-1 {
				s5 += matrix[i][j]
			}
			if i == col-1 {
				s6 += matrix[i][j]
			}
			if j == rowIndex {
				s7 += matrix[i][j]
			}
			if i == colIndex {
				s8 += matrix[i][j]
			}
		}
	}
	words = append(words, s1, s2, s3, s4, s5, s6, s7, s8)
	return words
}
