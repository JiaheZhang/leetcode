class Solution {
    public boolean isPalindrome(String s) {
    	s = s.toLowerCase();
    	int i = 0, j = s.length()-1;
    	while(i < j){
    		while(!Character.isLetterOrDigit(s.charAt(i)) && i < j){
    			i++;
    		}

    		while(!Character.isLetterOrDigit(s.charAt(j)) && i < j){
    			j--;
    		}
    		if (i < j && s.charAt(i) != s.charAt(j)) {
    			return false;
    		} else {
    			i++;
    			j--;
    		}
    	}

    	return true;
    }
}