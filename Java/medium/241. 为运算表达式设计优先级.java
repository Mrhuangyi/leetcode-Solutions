class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> ways = new ArrayList<>();
        for(int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if(c == '+' || c == '-' || c == '*') {
                List<Integer> left = diffWaysToCompute(input.substring(0, i));
                List<Integer> right = diffWaysToCompute(input.substring(i + 1));
                for(int l : left) {
                    for(int r : right) {
                        switch(c) {
                            case '+':
                                ways.add(l + r);
                                break;
                            case '-':
                                ways.add(l - r);
                                break;
                            case '*':
                                ways.add(l * r);
                                break;
                        }
                    }
                }
            }
        }
        if(ways.size() == 0) {
            ways.add(Integer.valueOf(input));
        }
        return ways;
    }
}
