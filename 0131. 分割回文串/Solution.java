class Solution {
	private List<List<String>> res = new ArrayList<>();
    public List<List<String>> partition(String s) {
    	traceBack(s, 0, new ArrayList<>());
    	return res;
    }

// aaabbaaa
    private void traceBack(String s, int start, List<String> tmp) {
    	if (start == s.length()) {
    		res.add(new ArrayList<>(tmp));
    		return;
    	}
    	for (int i = start+1; i <= s.length(); i++) {
    		String sub = s.substring(start, i);
    		if (isPalindrome(sub)) {
    			tmp.add(sub);
    			traceBack(s, i, tmp);
    			tmp.remove(tmp.size()-1);
    		}
    	}
    }

    private boolean isPalindrome(String s) {
    	int i = 0;
    	int j = s.length() - 1;
    	while(i < j) {
    		if (s.charAt(i) != s.charAt(j)) {
    			return false;
    		}
    		++i;
    		--j;
    	}
    	return true;
    }
}