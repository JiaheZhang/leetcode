#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long num = 0;

        while(x){
            num = num * 10 + x % 10;
            x /= 10;
        }

        if(num > INT_MAX || num < -INT_MAX) return 0;
        return num;
    }
};
