#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long div = dividend,divor = divisor;
        int sign;

        long num = 0;
        int i;
        if((div > 0 && divor > 0) || (div < 0 && divor < 0) ){
            sign = 1;
        }
        else{
            sign = -1;
        }

        div = abs(div);
        divor = abs(divor);

        while(div >= divor){
            i = 1;
            while(div > (divor<<i)){
                i++;
            }
            div -= (divor<<(i-1));
            num += (1 << (i-1));
        }

        if(sign == -1){
            num = -num;
        }

        if(num > INT_MAX || num < -INT_MAX-1) return INT_MAX;

        return num;
    }
};