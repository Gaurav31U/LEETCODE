class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]!=0)
                mat[i][j]+=min({mat[i+1][j],mat[i+1][j+1],mat[i][j+1]});
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans+=mat[i][j];
        return ans;
    }
};