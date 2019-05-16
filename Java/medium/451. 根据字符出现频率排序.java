class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        List<Character>[] bucket = new ArrayList[s.length() + 1];
        for(char c : map.keySet()) {
            int f = map.get(c);
            if(bucket[f] == null) {
                bucket[f] = new ArrayList<>();
            }
            bucket[f].add(c);
        }
        StringBuilder str = new StringBuilder();
        for(int i = bucket.length - 1; i >= 0; i--) {
            if(bucket[i] == null) {
                continue;
            }
            for(char c : bucket[i]) {
                for(int j = 0; j < i; j++) {
                    str.append(c);
                }
            }
        }
        return str.toString();
    }
}
