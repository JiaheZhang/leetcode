class Solution {
    public int longestConsecutive(int[] nums) {
    	Set<Integer> set = new HashSet<>();
    	for (int i : nums) {
    		set.add(i);
    	}
    	int res = 0;
    	for (int i : nums) {
    		if (set.contains(i - 1)) {
    			continue;
    		}
    		int len = 1;
    		int key = i + 1;
    		while(set.contains(key++)) {
    			len++;
    		}
    		res = Math.max(res, len);
    	}

    	return res;

    }
}