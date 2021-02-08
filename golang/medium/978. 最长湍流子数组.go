func maxTurbulenceSize(arr []int) int {
    len := len(arr)
    res := 1
    left, right := 0, 0
    for right < len - 1 {
        if left == right {
            if arr[left] == arr[left+1] {
                left++
            }
            right++
        } else {
            if arr[right-1] < arr[right] && arr[right] > arr[right+1] {
                right++
            } else if arr[right-1] > arr[right] && arr[right] < arr[right+1] {
                right++
            } else {
                left = right
            }
        }
        res = max(res, right - left + 1)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
