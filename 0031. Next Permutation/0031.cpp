#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0;
        for(int i = nums.size()-2;i >=0;i-- ){
            if(nums[i] < nums[i+1]){

                for(int j = i+1;j<nums.size();j++){
                    if(nums[i] < nums[j]){
                        index = j;
                    }
                    else break;
                }
                int tmp = nums[i];
                nums[i] = nums[index];
                nums[index] = tmp;
                reverse(nums.begin()+i+1,nums.end());
                return;
                
            }
        }
        reverse(nums.begin(),nums.end());
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    s.nextPermutation(v);
    cout<<v[0]<<v[1]<<v[2]<<endl;
    return 0;
}