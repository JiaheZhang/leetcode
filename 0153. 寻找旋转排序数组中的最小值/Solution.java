class Solution {
    public int findMin(int[] nums) {
    	int left = 0;
    	int right = nums.length;
    	if (right == 1) {
    		return nums[0];
    	}
    	while(left < right) {
    		int mid = left + (right - left) / 2;
    		if (nums[mid] < nums[mid - 1]) {
    			return nums[mid];
    		}
    		if (nums[mid] > nums[left]) {
    			left = mid;
    		} else {
    			right = mid;
    		}
    	}
    	return nums[0];
    }
}