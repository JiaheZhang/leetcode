#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


class Solution {
public:
    bool is_twoGraph = true;
    void bfs(vector<vector<int>>& graph, vector<int>& class_set, int node){
        if(!this->is_twoGraph) return;
        if(class_set[node] != 0) return;
        queue<int> my_que;

        int que_front;
        class_set[node] = 1;
        my_que.push(node);

        while(!my_que.empty()){
            que_front = my_que.front();
            my_que.pop();
            // this_class = class_set[que_front];

            for(int i = 0;i < graph[que_front].size();i++){
                if(class_set[graph[que_front][i]] == class_set[que_front]){
                    // return false;
                    this->is_twoGraph = false;
                    return;
                }
                else if(class_set[graph[que_front][i]] == 0){
                    if(class_set[que_front] == 1){
                        class_set[graph[que_front][i]] = -1;
                    }
                    else{
                        class_set[graph[que_front][i]] = 1;
                    }
                    my_que.push(graph[que_front][i]);
                }
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n <= 2) return true;
        vector<int> class_set(n,0);

        for(int i = 0;i < n;i++){
            bfs(graph, class_set, i);
        }
        return is_twoGraph;
    }
};
