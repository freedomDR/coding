package main

import (
	"fmt"
	"strings"
	"time"
)

var find map[string]int

func bfs(s string, des string, a []string, b []string, ans *int) bool {
	// time.Sleep(500 * time.Millisecond)
	// fmt.Println(s, nums)
	queue := make([]string, 0)
	queue = append(queue, s)
	for len(queue) != 0 {
		if *ans > 10 {
			break
		}
		temp := make([]string, 0)
		for i := 0; i < len(queue); i++ {
			if queue[i] == des {
				return true
			}
			for j := 0; j < len(a); j++ {
				prefix := ""
				s = queue[i]
				for {
					pos := strings.Index(s, a[j])
					if pos != -1 {
						ss := prefix + s[:pos] + b[j] + s[pos+len(a[j]):]
						if find[ss] == 0 {
							find[ss] = 1
							temp = append(temp, ss)
						}
						prefix = s[:pos+len(a[j])]
						s = s[pos+len(a[j]):]
					} else {
						break
					}
				}
			}
		}
		queue = temp
		*ans = *ans + 1
	}
	return false
}

func main() {
	var A, B string
	a := make([]string, 0, 100)
	b := make([]string, 0, 100)
	fmt.Scan(&A, &B)
	for {
		var aa, bb string
		nums, err := fmt.Scan(&aa, &bb)
		if nums != 2 || err != nil {
			break
		}
		a = append(a, aa)
		b = append(b, bb)
	}
	start := time.Now()
	ans := 0
	find = make(map[string]int)
	res := bfs(A, B, a, b, &ans)
	if res && ans <= 10 {
		fmt.Println(ans)
	} else {
		fmt.Println("NO ANSWER!")
	}
	cost := time.Since(start)
	fmt.Printf("cost=[%s]", cost)
}
