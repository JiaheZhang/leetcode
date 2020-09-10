class Solution {
    public String largestNumber(int[] nums) {
        if (nums.length == 0) {
            return "";
        }
    	String[] strs = new String[nums.length];
    	for (int i = 0; i < nums.length; ++i) {
    		strs[i] = String.valueOf(nums[i]);
    	}
    	Arrays.sort(strs, (o1, o2) -> {
            String a = o1 + o2;
            String b = o2 + o1;
            return b.compareTo(a);
        });

        if (strs[0].equals("0")) {
            return "0";
        }
        
    	return String.join("", strs);

    }
}