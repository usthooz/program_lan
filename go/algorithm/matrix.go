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
	q1()
}

// When words lie on either straight line in 8 directions(horizontal, vertical or diagonal)，get all words.
func q1() {
	// invalid
	if col != row || col%2 == 0 {
		return
	}
	// get center index
	colIndex := col/2 + col%2 - 1
	rowIndex := row/2 + row%2 - 1
	for i := 1; i < row-rowIndex; i++ {
		ozlog.Infof("%s", matrix[colIndex][colIndex-i])
	}
}
