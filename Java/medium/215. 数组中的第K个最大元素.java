class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int e : nums) {
            pq.add(e);
            if(pq.size() > k) {
                pq.poll();
            }
        }
        return pq.peek();
    }
}


class Solution {
    public int findKthLargest(int[] nums, int k) {
        k = nums.length - k;
        int l = 0, h = nums.length - 1;
        while(l < h) {
            int j = partition(nums, l, h);
            if(j == k) {
                break;
            } else if(j < k) {
                l = j + 1;
            } else {
                h = j - 1;
            }
        }
        return nums[k];
    }
    private int partition(int a[], int left, int right) {
    int pivot = a[left];
    int i = left;
    int j = right + 1;
    while (true) {
        while (a[++i] < a[left] && i < right) ;
        while (a[--j] > a[left] && j > left) ;
        if (i >= j) {
            break;
        }
        swap(a, i, j);
    }
    swap(a, left, j);
    return j;
}
    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
