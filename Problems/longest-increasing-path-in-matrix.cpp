#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &cache, int i, int j, int prev){
        if(i<0 || i>= matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<= prev){
            return 0;
        }
        if(cache[i][j]!=-1) return cache[i][j];

        int dR[4] = {-1,1,0,0};
        int dC[4] = {0,0,-1,1};
        int currentBest = 0;

        for(int idx=0; idx<4; idx++){
            int nextRow = i+dR[idx];
            int nextCol = j +dC[idx];
            currentBest = max(currentBest, 1+dfs(matrix, cache, nextRow, nextCol, matrix[i][j]));
        }

        return cache[i][j]=currentBest;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                res = max(res, dfs(matrix, cache, i,j,-1));
            }
        }
        return res;
    }
};