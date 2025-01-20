class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat){
        int n=mat.size(),m=mat[0].size();
        vector<int> row(n,m),col(m,n);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]=make_pair(i,j);
            }
        }
        for(int i=0;i<arr.size();i++){
            auto it=mp[arr[i]];
            row[it.first]--;
            col[it.second]--;
            if(row[it.first]==0 || col[it.second]==0){
                return i;
            }
        }
        return -1;
    }
};