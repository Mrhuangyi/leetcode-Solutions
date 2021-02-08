func maximumWealth(accounts [][]int) int {
    res := 0
    temp := 0
    for i := 0; i < len(accounts); i++ {
        for j := 0; j < len(accounts[0]); j++ {
            temp += accounts[i][j]
        }
        if temp > res {
            res = temp
        }
        temp = 0
    }
    return res
}
