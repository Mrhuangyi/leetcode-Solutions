class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        List<Integer>[] bucket = new ArrayList[nums.length + 1];
        for(int key : map.keySet()) {
            int frequency = map.get(key);
            if(bucket[frequency] == null) {
                bucket[frequency] = new ArrayList<>();
            }
            bucket[frequency].add(key);
        }
        List<Integer> top = new ArrayList<>();
        for(int i = bucket.length - 1; i >= 0 && top.size() < k; i--) {
            if(bucket[i] == null) {
                continue;
            }
            if(bucket[i].size() <= (k - top.size())) {
                top.addAll(bucket[i]);
            } else {
                top.addAll(bucket[i].subList(0, k - top.size()));
            }
        }
        return top;
    }
}
