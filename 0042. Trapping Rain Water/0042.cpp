#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;

        int i = 0,j = height.size()-1;

        int left_max = height[i],right_max = height[j];
        int sum = 0;
        while(i <= j){
            if(left_max > right_max){
                if(height[j] > right_max){
                    right_max = height[j];
                }
                else{
                    sum += (right_max - height[j]);
                }
                j--;
            }
            else{
                if(height[i] > left_max){
                    left_max = height[i];
                }
                else{
                    sum += (left_max - height[i]);
                }
                i++;
            }
            
        } 
        return sum;
    }
};