package main

import "fmt"

const (
	N = 13 // Set the number of prime numbers here.
)

func main() {
	var x uint64 = 2
	var primes = [N]uint64{}

	for i := range N {
		for {
			z := false
			if x > 2 && x%2 == 0 {
				x++
				continue
			}
			for j := uint64(3); j < x; j++ {
				if x%j == 0 {
					z = true
					break
				}
			}
			if z {
				x++
				continue
			}
			primes[i] = x
			x++
			break
		}
	}

	for _, p := range primes {
		fmt.Println(p)
	}
}
