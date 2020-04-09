#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> result;
    void trace_back(string& gen,int n,int left_num, int right_num,int len){
        if(len == 2*n){
            result.push_back(gen);
            return;
        }
        if(left_num < n){
            gen[len] = '(';
            trace_back(gen,n,left_num+1,right_num,len+1);
        }
        if(right_num < left_num){
            gen[len] = ')';
            trace_back(gen,n,left_num,right_num+1,len+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string gen(2*n,'0');
        trace_back(gen,n,0,0,0);
        return result;
    }
};