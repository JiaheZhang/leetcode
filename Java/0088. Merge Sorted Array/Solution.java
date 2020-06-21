class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] tmp = Arrays.copyOf(nums1,m);
        int i = 0,j = 0;
        int index = 0;
        while(i < m && j < n){
        	if (tmp[i] < nums2[j]) {
        		nums1[index++] = tmp[i++];
        	} else {
        		nums1[index++] = nums2[j++];
        	}
        }
        if (i == m) {
        	for (;j < n;j++) {
        		nums1[index++] = nums2[j];
        	}
        }
        if (j == n) {
        	for (;i < m;i++) {
        		nums1[index++] = tmp[i];
        	}
        }
    }
}