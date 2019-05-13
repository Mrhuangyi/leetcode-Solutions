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
    while(left < right) {
        while(left < right && a[right] >= pivot) {
            right--;
        }
        a[left] = a[right];
        while(left < right && a[left] <= pivot) {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
    }
    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
