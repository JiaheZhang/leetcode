#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<double> posib;
    vector<vector<int>> tree;
    queue<int> fog;
    vector<int> is_visit;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        posib.resize(n,0);
        posib[0] = 1;
        if (t == 0) return posib[target-1];

        tree.resize(n);
        is_visit.resize(n,0);
        fog.push(0);
        is_visit[0] = 1;

        // consturct tree
        tree[0].push_back(0);
        for (int i = 0;i < edges.size();i++){
            tree[edges[i][0]-1].push_back(edges[i][1]-1);
            tree[edges[i][1]-1].push_back(edges[i][0]-1);
        }

        for (int i = 0;i < t;i++){
            queue<int> next_que;
            while (!fog.empty())
            {
                
                int get_fog = fog.front();
                fog.pop();
                if(tree[get_fog].size() != 1){
                    for(int j = 0;j < tree[get_fog].size();j++){
                        if(is_visit[tree[get_fog][j]]) continue;
                        posib[tree[get_fog][j]] = 1.0 / (tree[get_fog].size()-1) * posib[get_fog];
                        next_que.push(tree[get_fog][j]);
                    }
                    posib[get_fog] = 0.0;
                    is_visit[get_fog] = 1;
                }
            }
            fog = next_que;
            

        }
        for(int i = 0;i < posib.size();i++){
            cout<<posib[i]<<endl;
        }

        return posib[target-1];
    }
};

int main(){
    Solution S;
    vector<vector<int>> edges = {{2,1},{3,1},{4,2},{5,4},{6,5},{7,2}};
    cout<<S.frogPosition(7,edges,3,2);
}