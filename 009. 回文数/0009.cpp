#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        if(str[0] == '-') return false;

        int i = 0,j = str.size()-1;

        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            
            i++;
            j--;
        }

        return true;
    }
};