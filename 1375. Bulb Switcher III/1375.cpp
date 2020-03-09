#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int max_light = 0;
        int num = 0;
        int index_ok = 0;
        vector<int> light_status(light.size(),1);
        for (int i = 0; i < light.size();i++){
            light_status[light[i] - 1] = 0;
            max_light = max(max_light,light[i]-1);
            int tmp_sum = 0;
            for(int j = index_ok;j <= max_light;j++){
                if(light_status[j] == 1)
                {
                    tmp_sum = 1;
                    break;
                }
            }
            if (tmp_sum == 0) {
                num++;
                index_ok = max_light;
                }
        }
        return num;
    }
};