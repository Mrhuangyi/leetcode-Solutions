func runningSum(nums []int) []int {
    len := len(nums)
    arr := make([]int, len)
    arr[0] = nums[0]
    for i := 1; i < len; i++ {
        arr[i] = nums[i] + arr[i-1]
    }
    return arr
}
