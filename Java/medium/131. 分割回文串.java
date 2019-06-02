class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        dfs(s, res, temp);
        return res;
    }
    
    private void dfs(String s, List<List<String>> res, List<String> temp) {
        if(s.length() == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = 0; i < s.length(); i++) {
            if(isPalindrome(s, 0, i)) {
                temp.add(s.substring(0, i + 1));
                dfs(s.substring(i + 1), res, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
    private boolean isPalindrome(String s, int begin, int end) {
        while(begin < end) {
            if(s.charAt(begin++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }
}
