import java.util.Arrays;

class s0066{
    public int[] plusOne(int[] digits) {
        int cnt = 1;
        int tmp = 0;
        for(int i = digits.length-1;i >= 0;i--){
            tmp = (digits[i] + cnt) % 10;
            cnt = (digits[i] + cnt) / 10;
            digits[i] = tmp;
        }
        if(cnt == 0) return digits;
        else {
            int[] res = new int[digits.length+1];
            res[0] = cnt;
            for(int i = 1;i < res.length;i++){
                res[i] = digits[i-1];
            }
            return res;
        }

    }

    public static void main(String[] args) {
        // s0066 s  = new s0066();

        // int[] digits = {9,9,8};
        // int[] res = s.plusOne(digits);
        // System.out.println(Arrays.toString(res));
        int[] a = {1,2,3,4};
        a = new int[5];
        System.out.println(Arrays.toString(a));
    }
}