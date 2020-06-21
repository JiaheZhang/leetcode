// O(N^2) bad
class Solution {
    public int removeDuplicates(int[] nums) {
    	int len = nums.length;
    	if (len <= 2) {
    		return len;
    	}
    	int i = 2;
    	while(i < len){
    		if (nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) {
    			for (int j = i;j < len-1 ;++j ) {
    				nums[j] = nums[j+1];
    			}
    			--len;
    		} else {
    			++i;
    		}
    	}
    	return len;
    }
}


// O(N)
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 1,j = 1;
        int count = 1;
        while(i < nums.length){
            if (nums[i] == nums[i-1]) {
                count++;
            } else{
                count = 1;
            }

            if (count > 2) {
                i++;
                continue;                
            }else{
                nums[j++] = nums[i++];
            }
        }
        return j;
    }
}