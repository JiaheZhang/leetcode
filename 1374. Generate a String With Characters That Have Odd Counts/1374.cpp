#include <iostream>
#include <string>

using namespace std;

class Solution {
    
public:
    string generateTheString(int n) {
        string a = "";
        if(n % 2 == 1){
            a.append(n,'a');
        }
        else{
            a = a + 'b';
            a.append(n-1,'a');
        }
        return a;
    }
};