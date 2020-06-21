class Solution {
    public boolean search(int[] nums, int target) {
    	int left = 0, right = nums.length-1;

    	while(left <= right) {
    		int mid = left + ((right-left) >> 1);
    		if (nums[mid] == target) {
    			return true;
    		} else if (nums[left] < nums[mid]) {
    			//left is ok
    			if (nums[left] <= target && target < nums[mid]) {
    				right = mid - 1;
    			} else {
    				left = mid + 1;
    			}
    		} else if (nums[mid] < nums[right]) {
    			//right is ok
    			if (nums[mid] < target && target <= nums[right]) {
    				left = mid + 1;
    			} else {
    				right = mid - 1;
    			}
    		} else if (nums[left] == nums[mid]) {
    			left++;
    		} else if (nums[mid] == nums[right]) {
    			right--;
    		}
    	}
    	return false;
    }
}