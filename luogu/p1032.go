package main

import (
	"fmt"
	"strings"
	"time"
)

var find map[string]int

func bfs(s string, des string, a []string, b []string, nums int, ans *int) {
	// time.Sleep(5000 * time.Millisecond)
	// fmt.Println(s, nums)
	if nums > 10 || nums > *ans {
		return
	}
	if s == des {
		if *ans > nums {
			*ans = nums
		}
		return
	}
	for i := 0; i < len(a); i++ {
		prefix := ""
		for {
			pos := strings.Index(s, a[i])
			if pos != -1 {
				ss := prefix + s[:pos] + b[i] + s[pos+len(a[i]):]
				if find[ss] == 0 || find[ss] > nums+1 {
					find[ss] = nums + 1
					bfs(ss, des, a, b, nums+1, ans)
				}
				prefix = s[:pos+len(a[i])]
				s = s[pos+len(a[i]):]
			} else {
				break
			}
		}
	}
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
	ans := 100
	find = make(map[string]int)
	bfs(A, B, a, b, 0, &ans)
	if ans <= 10 {
		fmt.Println(ans)
	} else {
		fmt.Println("NO ANSWER!")
	}
	cost := time.Since(start)
	fmt.Printf("cost=[%s]", cost)
}
