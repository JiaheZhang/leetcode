
public class s0060 {
    public String getPermutation(int n, int k) {
        // Collections.binarySearch(list, key)
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        for (int i = 0; i < k-1; i++) {
            nextPermutation(nums);
        }
        // 123
        // 132
        // 213
        StringBuilder str = new StringBuilder();
        for(int i : nums){
            str.append(i);
        }
        return str.toString();
        
    }

    public void swap(int[] a,int i, int j){

        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

    }

    public void nextPermutation(int[] nums){
        // 3,4,5,7,6,2,1 -> 3,4,5,1,2,6,7 -> 3,4,6,1,2,5,7

        if(nums.length <= 1) return;
        int i = nums.length-2;
        while(i >= 0 && nums[i] > nums[i+1]){
            i--;
        }

        reverse(nums, i+1, nums.length-1);

        // Arrays.sort(nums, i+1, nums.length);

        for(int j = i+1;j < nums.length;j++){
            if(nums[j] > nums[i]){
                swap(nums,i,j);
                break;
            }
        }

    }

    public void reverse(int[] nums,int left, int right){
        while(left < right){
            int tmp = nums[left];
            nums[left++] = nums[right];
            nums[right--] = tmp; 
        }
    }
}