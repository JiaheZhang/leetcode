#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> my_stack;
        int max_len = 0;
        int tmp_len = 0;

        for (int i = 0;i < s.size();i++){
            if(s[i] == '('){
                if(my_stack.empty()){
                    my_stack.push(i-1);
                    my_stack.push(i);
                }
                else{
                    my_stack.push(i);
                }
            }
            else if(s[i] == ')'){
                if(!my_stack.empty()){
                    my_stack.pop();
                    if(!my_stack.empty()){
                        tmp_len = i - my_stack.top();
                        if(tmp_len > max_len) max_len = tmp_len;
                    }
                        
                }
            }
        }
        return max_len;



    }
};


int main(){

    Solution s;
    string str = ")()())";
    cout<<s.longestValidParentheses(str)<<endl;    
    return 0;
}