class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        vector<int> factor;
        for(int i=1;i<=sqrt(sum);i++){
            if(sum%i==0){
                factor.push_back(sum/i);
                factor.push_back(i);
                if(i*i==sum)factor.pop_back();
            }
        }
        sort(factor.begin(),factor.end());
        vector<int> adj[20001];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int vis[20001];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        bool possible=true;
        auto dfs=[&](auto&& dfs,int i,int su)->int{
            vis[i]=1;
            int val=nums[i];
            for(auto it:adj[i]){
                if(vis[it]==0){
                    int s=dfs(dfs,it,su);
                    if(s<0)return -1;
                    val+=s;   
                }
            }
            if(val>su){
                possible=false;
                return -1;
            }
            if(val==su)return 0;
            return val;
        };
        int ans=0;
        for(auto it:factor){
            cnt=0;
            possible=true;
            memset(vis,0,sizeof(vis));
            dfs(dfs,0,it);
            if(possible)ans=max(ans,sum/it-1);
            
        }
        return ans;
    }
};