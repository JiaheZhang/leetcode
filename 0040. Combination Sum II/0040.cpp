#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    // int last_pop=-1;
    void DFS(vector<int>& comb,int start, int target,vector<int>& candidates){
        if(target == 0){
            result.push_back(comb);
            return;
        }
        if(target < 0) return;
        for(int i = start;i < candidates.size();i++){
            if(target-candidates[i] < 0) break;
            if(i > start && candidates[i] == candidates[i-1]) continue;
            comb.push_back(candidates[i]);
            DFS(comb,i+1,target-candidates[i],candidates);
            // last_pop = comb.back();
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        sort(candidates.begin(),candidates.end());
        DFS(comb,0,target,candidates);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};

    s.combinationSum2(candidates,8);
    return 0;
}