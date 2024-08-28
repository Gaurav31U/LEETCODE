class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l=0,r=3001;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        auto grp=grid;
        int n=grid.size();
        auto dfs=[&](auto&& dfs,int i,int j,int val)->void{
            grp[i][j]=-1;
            for(int k=0;k<4;k++){
                int ni=dx[k]+i;
                int nj=dy[k]+j;
                if(ni>=0 && nj>=0 && ni<n && nj<n && grp[ni][nj]!=-1 && grp[ni][nj]<=val){
                    dfs(dfs,ni,nj,val);
                }
            }
        };
        int ans=3000;
        while(l<=r){
            int mid=(l+r)/2;
            grp=grid;
            if(grp[0][0]<=mid)
            dfs(dfs,0,0,mid);
            if(grp[n-1][n-1]==-1){
                ans=min(mid,ans);
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};