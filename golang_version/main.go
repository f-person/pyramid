package main

import "fmt"

const n = 4

func main() {
	var (
		left   = 0
		right  = 2*n - 2
		top    = 0
		bottom = n - 1
		num    = 1
	)
	var arr [n][2*n - 1]int

	// for row:=0; row<n;row++{
	// 	for col:=0;col<=2*n-2;col++{
	// 		arr[row][col]=0
	// 	}
	// }
	for ok := true; ok; ok = (bottom >= top) {
		fixright := right
		for col := left; col <= right; col++ {
			arr[bottom][col] = num
			num++
		}

		for row := bottom - 1; row >= top; row-- {
			right--
			arr[row][right] = num
			num++
		}

		for row := top + 1; row <= bottom-1; row++ {
			right--
			arr[row][right] = num
			num++
		}

		top++
		bottom--
		left += 2
		right = fixright - 2
	}

	for row := 0; row < n; row++ {
		for col := 0; col <= 2*n-2; col++ {
			if arr[row][col] != 0 {
				fmt.Printf("%d\t", arr[row][col])
			} else {
				fmt.Print("\t")
			}
		}
		fmt.Println()
	}

}
