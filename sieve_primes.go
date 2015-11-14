package main

import (
  "fmt"
  "math"
  "os"
  "strconv"
)

type LinkNode struct {
    value int
    next *LinkNode
}

func CountAllNodes(start *LinkNode) int{
  num := 0
  current := start;
  for {
    if(current.next == nil) {
      break
    } else {
      current = current.next
      num += 1
    }
  }
  return num
}

// 2 3 5 7....
func main() {
  if(len(os.Args) < 2) {
    fmt.Printf("arg error")
    os.Exit(1)
  }
  
  max64, err := strconv.ParseInt(os.Args[1], 10, 64)
  if err != nil {
    panic("parse error")
  }
  max := int(max64)
  end := math.Ceil(math.Sqrt(float64(max)))

  fmt.Printf("Max = %d End = %d \n", max, int(end))

  start := new(LinkNode)
  var current *LinkNode = start

  (*current).next = new(LinkNode)
  (*current).next.next = nil
  (*current).value = 2
  current = (*current).next

  for i := 2;i < max;i += 2 {
    (*current).next = new(LinkNode)
    (*current).next.next = nil
    (*current).value = i + 1
    current = (*current).next
  }
  current = start

  for {
    if current.next == nil || current.next.value == 0 {
      break
    } 
    num := current.value

    seek := current
    for {
      if seek.next == nil || seek.next.value == 0 {
        break
      }
      if seek.next.value % num == 0 {
          seek.next = seek.next.next
      }
      seek = seek.next
      if seek == nil {
        break
      }
    }
    current = current.next
  }
  fmt.Printf("%d primes\n", CountAllNodes(start))
}
