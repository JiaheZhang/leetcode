/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true


 */

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int len = s.size();
        for(int i = 0;i < len;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
            else{
                if(stack.empty()) return false;
                else{
                    if(s[i] == ')' && stack.top() == '(') stack.pop();
                    else if(s[i] == ']' && stack.top() == '[') stack.pop();
                    else if(s[i] == '}' && stack.top() == '{') stack.pop();
                    else return false;
                }
            }
        }
        if(stack.empty()) return true;
        else return false;

    }
};
