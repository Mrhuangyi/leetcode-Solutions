class Solution {
    private final static HashSet<Character> vowels = new HashSet<Character>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')); 
    public String reverseVowels(String s) {
        int i = 0;
        int j = s.length() - 1;
        char res[] = new char[s.length()];
        while(i <= j) {
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if(!vowels.contains(ci)) {
                res[i++] = ci;
            } else if(!vowels.contains(cj)) {
                res[j--] = cj;
            } else {
                res[i++] = cj;
                res[j--] = ci;
            }
        }
        return new String(res);
    }
}
