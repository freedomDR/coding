package main

import "fmt"

func isBoomerang(point [][]int) bool {
	if point[0][0] == point[1][0] && point[1][0] == point[2][0] {
		return false
	}
	if point[0][1] == point[1][1] && point[1][1] == point[2][1] {
		return false
	}
	if float64(point[0][0]-point[1][0])/float64(point[0][1]-point[1][1]) != float64(point[0][0]-point[2][0])/float64(point[0][1]-point[2][1]) && (point[0][0] != point[1][0] || point[0][1] != point[1][1]) && (point[0][0] != point[2][0] || point[0][1] != point[2][1]) && (point[1][0] != point[2][0] || point[1][1] != point[2][1]) {
		return true
	} else {
		return false
	}
}
