#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int max_dis = 99999999;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> edges(N,vector<int>(N,-1));
        vector<int> dist(N,max_dis);
        vector<int> point_set(N,0);
        int max_init = max_dis;
        int min_index = 0;
        K--;
        dist[K] = 0;
        point_set[K] = 1;

        for (int i = 0;i < times.size();++i){
            edges[times[i][0]-1][times[i][1]-1] = times[i][2];
        }

        // intilize dist
        for(int i = 0;i < N;++i){
            if(point_set[i] == 0){
                if(edges[K][i] >= 0 && edges[K][i] < dist[i]){
                    dist[i] = edges[K][i];
                }
            }
        }


        for(int i = 0;i < N;++i){


            max_init = max_dis;
            min_index = 0;
            // find min
            for(int j = 0;j < N;++j){
                if(point_set[j] == 0){
                    if(dist[j] < max_init){
                        max_init = dist[j];
                        min_index = j;
                    }
                }
            }

            if(max_init == max_dis)  break;
            // into set
            point_set[min_index] = 1;

            // updata dist
            for(int j = 0;j < N;++j){
                if(point_set[j] == 0){
                    if(edges[min_index][j] >= 0 && dist[min_index] + edges[min_index][j] < dist[j]){
                        dist[j] = dist[min_index] + edges[min_index][j];
                    }
                }
            }
        }

        max_init = 0;
        for(int j = 0;j < N;++j){
            if(dist[j] > max_init){
                max_init = dist[j];
            }
        }
        if(max_init == max_dis) return -1;
        else return max_init;

    }
};


int main(){
    // int a = 1;
    vector<vector<int>> a = {{2,1,1},{2,3,1},{3,4,1}};
    Solution S;
    cout<<S.networkDelayTime(a, 4, 2);
    return 0;
}