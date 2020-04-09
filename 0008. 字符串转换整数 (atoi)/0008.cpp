#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        int i = 0;
        long long num = 0;;
        bool is_neg = false;

        while(str[i] == ' '){
            i++;
        }
        if(str[i] == '-'){
            is_neg = true;
            i++;
        }
        else if(str[i] == '+'){
            i++;
        }

        for(;i < str.size();i++){
            if(isdigit(str[i])){
                num *= 10;
                num = num + (str[i] - '0');
                if(num > INT_MAX){
                    break;
                }
            }
            else{
                break;
            }
        }

        if(is_neg){
            num = -num;
        }

        if(num > INT_MAX){
            return INT_MAX;
        }

        if(num < -INT_MAX-1){
            return -INT_MAX-1;
        }


        return num;
        
        
    }
};