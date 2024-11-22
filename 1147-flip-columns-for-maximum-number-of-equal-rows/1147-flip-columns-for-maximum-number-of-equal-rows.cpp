class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> row(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(auto it:matrix[i])if(it==1)cnt++;
            row[i]=cnt;
        }
        int ans=1;
        auto grid=matrix;
        int m=matrix[0].size();
        auto temp=row;
        for(int i=0;i<n;i++){
            // matrix=grid;
            row=temp;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]==0){
                            row[k]++;
                        }else{
                            row[k]--;
                        }
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(row[j]==m || row[j]==0)cnt++;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};