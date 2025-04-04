class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ind(n,0);
        for(auto it:edges)ind[it[1]]++;
        int cnt=0,ans=-1;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                cnt++;
                ans=i;
            }
        }
        return cnt==1?ans:-1;
    }
};