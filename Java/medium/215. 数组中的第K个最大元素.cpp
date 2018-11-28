/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

*/

class Solution {
    public int findKthLargest(int[] nums, int k) {
        shuffle(nums);
        k = nums.length - k;
        int low = 0;
        int high = nums.length - 1;
        while(low < high) {
            int pivot = partition(nums, low, high);
            if(pivot < k) {
                low = pivot + 1;
            } else if(pivot > k) {
                high = pivot - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
    int partition(int[] a, int low, int high) {
        int i = low;
        int j = high + 1;
        while(true) {
            while(j < high && less(a[++i], a[low]));
            while(j > low && less(a[low], a[--j]));
            if(i >= j) {
                break;
            }
            exch(a, i, j);
        }
        exch(a, low, j);
                    return j;
    }
    void exch(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    boolean less(int v, int w) {
        return v < w;
    }
    void shuffle(int a[]) {
        Random random = new Random();
        for(int i = 1; i < a.length; i++) {
            int r = random.nextInt(i + 1);
            exch(a, i, r);
        }
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int val : nums) {
            pq.offer(val);
            if(pq.size() > k) {
                pq.poll();
            }
        }
        return pq.peek();
    }
}
