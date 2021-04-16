func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    if x == 0 {
        return true
    }
    reverseNum := 0
    tempX := x
    for x > 0 {
        temp := x % 10
        x = x / 10
        reverseNum = reverseNum * 10 + temp
    }
    if reverseNum == tempX {
        return true
    } else {
        return false
    }
}
