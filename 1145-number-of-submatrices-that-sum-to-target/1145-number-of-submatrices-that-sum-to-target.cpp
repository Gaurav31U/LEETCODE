class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int s=0;
                for(int k=0;k<n;k++){
                    s+=(matrix[k][j]-(i>0?matrix[k][i-1]:0));
                    if(mp.count(s-target))ans+=mp[s-target];
                    mp[s]++;
                }   
            }
        }
        return ans;
    }
};