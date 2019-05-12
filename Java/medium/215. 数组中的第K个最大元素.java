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
