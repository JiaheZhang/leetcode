#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return "";
        string result;
        int i = s.size()-1;
        while (i >= 0){
            if(s[i] != ' '){
                for(int j = i;j >= 0;j--){
                    if(s[j] == ' '){
                        result.append(s.substr(j+1,i-j));
                        result.append(" ");
                        i = j;
                        break;
                    }
                    if(j == 0){
                        result.append(s.substr(0,i+1));
                        // result.append(" ");
                        i = j;
                    }
                }
            }
            i--;
        }

        if(result.size() == 0) return "";

        if(result.back() == ' '){
            result.erase(result.end()-1);
        }
        return result;
        
    }
};