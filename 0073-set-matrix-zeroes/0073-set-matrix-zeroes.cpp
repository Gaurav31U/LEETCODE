class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0)tmp.push_back({i,j});
            }
        }
        for(auto it:tmp){
            for(int i=0;i<matrix.size();i++){
                matrix[i][it.second]=0;
            }
            for(int i=0;i<matrix[0].size();i++){
                matrix[it.first][i]=0;
            }
        }
    }
};