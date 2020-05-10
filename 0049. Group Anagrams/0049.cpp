#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


// class Solution {
// public:
//     bool is_same_set(vector<int>& set1, vector<int>& set2){
//         for(int i = 0;i < set1.size();i++){
//             if(set1[i] != set2[i]) return false;
//         }
//         return true;
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         vector<vector<int> > dict_set;
//         for(int i = 0;i < strs.size();i++){
//             vector<int> my_set(26,0);
//             bool is_same = false;
//             for(int j = 0;j < strs[i].size();j++){
//                 my_set[strs[i][j]-'a']++;
//             }
//             for(int j = 0;j < dict_set.size();j++){
//                 if(is_same_set(my_set,dict_set[j])){
//                     is_same = true;
//                     res[j].push_back(strs[i]);
//                     break;
//                 }
//             }
//             if(!is_same){
//                 dict_set.push_back(my_set);
//                 res.push_back({strs[i]});
//             }
            
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> my_map;
        vector<vector<string>> res;
        for(int i = 0;i < strs.size();i++){
            string str_tmp = strs[i];
            sort(str_tmp.begin(),str_tmp.end());
            auto it = my_map.find(str_tmp);
            if(it != my_map.end()){
                it->second.push_back(strs[i]);
            }
            else{
                my_map[str_tmp] = {strs[i]};
            }
        }

        for(auto it = my_map.begin();it != my_map.end();it++){
            res.push_back(it->second);
        }


        return res;


    }
};