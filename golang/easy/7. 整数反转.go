func reverse(x int) int {
    res := 0
    if x == 0 {
        return x
    }
    flag := 1
    if x < 0 {
        flag = -1
        x = -x
    }
    for x > 0 {
        temp := x % 10
        x = x / 10
        res = res * 10 + temp
    }
    if res > math.MaxInt32 {
        return 0
    }
    if flag == 1 {
        return res
    } else {
        return res * flag
    }
}
