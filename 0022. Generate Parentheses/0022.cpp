/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    void gen_paren(int num_stack,string s,vector<string>& result,int num_left){
        if(num_stack > 0){
            if(num_left == 0){
                while(num_stack > 0){
                    s.push_back(')');
                    num_stack--;
                }
                result.push_back(s);
            }
            else{
                string t = s;
                s.push_back('(');
                num_stack++;
                num_left--;
                gen_paren(num_stack,s,result,num_left);
                
                t.push_back(')');
                num_stack--;
                num_stack--;
                num_left++;
                gen_paren(num_stack,t,result,num_left);
            }
        }
        else{
            if(num_left > 0){
                s.push_back('(');
                num_stack++;
                num_left--;
                gen_paren(num_stack,s,result,num_left);
            }
            else{
                result.push_back(s);
                return;
            }
            
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        gen_paren(0,s,result,n);
        return result;
    }
};

    

