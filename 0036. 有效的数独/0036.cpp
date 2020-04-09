#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> my_set;
        for(int i = 0;i < 9;i++){

            my_set.clear();
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                if(my_set.find(board[i][j]) != my_set.end()){
                    return false;
                }
                my_set.insert(board[i][j]);
            }
            
        }

        for(int i = 0;i < 9;i++){

            my_set.clear();
            for(int j = 0;j < 9;j++){
                if(board[j][i] == '.') continue;
                if(my_set.find(board[j][i]) != my_set.end()){
                    return false;
                }
                my_set.insert(board[j][i]);
            }
            
        }


        for(int i = 0;i <= 6;i+=3){
            for(int j = 0;j <= 6;j+=3){
                my_set.clear();
                for(int n = i;n <= i+2;n++){
                    for(int m = j;m <= j+2;m++){
                        if(board[n][m] == '.') continue;
                        if(my_set.find(board[n][m]) != my_set.end()){
                            return false;
                        }
                        my_set.insert(board[n][m]);
                        
                    }
                }
            }
        }
        

        return true;
    } 
};