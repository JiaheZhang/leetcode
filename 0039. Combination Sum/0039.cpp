#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void DFS(vector<int>& comb,int start, int target,vector<int>& candidates){
        if(target == 0){
            result.push_back(comb);
            return;
        }
        if(target < 0) return;
        for(int i = start;i < candidates.size();i++){
            if(target-candidates[i] < 0) break;
            comb.push_back(candidates[i]);
            DFS(comb,i,target-candidates[i],candidates);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        sort(candidates.begin(),candidates.end());
        DFS(comb,0,target,candidates);
        return result;
    }
};