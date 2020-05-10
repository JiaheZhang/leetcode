

public class s0050 {
    public double myPow(double x, int n) {
        if(n == 1) return x;
        if(n == 0) return 1.0;
        if(n == -1) return 1.0/x;

        double half = myPow(x,n>>1);
        double rest = myPow(x,n%2);

        return half * half * rest;
    }
    public static void main(String[] args){

    }
}


    // 暴力 n次乘法
    // public double myPow(double x, int n) {
    //     double res = 1;

    //     while(n > 0){
    //         res *= x;
    //         n--;
    //     }

    //     while(n < 0){
    //         res /= x;
    //         n++;
    //     }
    //     return res;
    // }
