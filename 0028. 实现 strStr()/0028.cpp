#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;

        string substr;
        int i = 0;
        while(i < haystack.size()){
            substr = haystack.substr(i,needle.size());
            if(substr.size() < needle.size()){
                return -1;
            }
            if(substr == needle){
                return i;
            }


            i++;
        }

        return -1;
    }
};