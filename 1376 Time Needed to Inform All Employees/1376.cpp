#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> time;
    queue<int> my_que;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        tree.resize(n);
        time.resize(n,0);

        // construct tree
        for (int i = 0; i < manager.size();i++){
            if(manager[i] != -1)
            {
                tree[manager[i]].push_back(i);
            }
        }

        // bfs
        my_que.push(headID);

        while(!my_que.empty()){
            int emple = my_que.front();
            my_que.pop();

            for(int i = 0;i < tree[emple].size();i++){
                time[tree[emple][i]] = time[emple] + informTime[emple];
                my_que.push(tree[emple][i]);
            }
        }
        

        return *max_element(time.begin(), time.end());


    }
};