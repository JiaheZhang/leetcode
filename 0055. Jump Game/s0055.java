public class s0055 {

    public boolean canJump(int[] nums) {
        int maxIndex = 0;
        int jump;

        for(int i = 0;i < nums.length-1;i++){
            if(i > maxIndex){
                break;
            }

            jump = nums[i] + i;

            if(jump > maxIndex){
                maxIndex = jump;
            }
            
        }

        return maxIndex >= nums.length-1;

    }
    

    public static void main(String[] args) {
        s0055 s = new s0055();
        int num[] = {0,2,3};
        System.out.println(s.canJump(num));
    }
}
