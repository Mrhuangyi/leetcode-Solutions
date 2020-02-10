public boolean valid(String word, String abbr) {
        int i = 0, j = 0;
        int len1 = word.length(), len2 = abbr.length();
        while(i < len1 && j < len2) {
            if(abbr.charAt(j) > '9' || abbr.charAt(j) <= '0') {
                if(word.charAt(i) != abbr.charAt(j)) {
                    return false;
                }
                i++;
                j++;
            } else {
                int count = 0;
                while(j < len2 && Character.isDigit(abbr.charAt(j))) {
                    count = count * 10 + (abbr.charAt(j) - '0');
                    j++;
                }
                i += count;
            }
        }
        return i == len1 && j == len2;
    }
