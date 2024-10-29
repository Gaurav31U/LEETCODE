class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int mx=0;
        vector<int> tmp(n+1,0);
        auto get=[&](auto&& get,int i,int sum)->int{
            if(2*i>=n && (2*i+1)>=n){
                mx=max(mx,sum+cost[i-1]);
                return cost[i-1];
            }
            int l=get(get,2*i,sum+cost[i-1]);
            int r=get(get,2*i+1,sum+cost[i-1]);
            tmp[i]=max(l,r);
            return tmp[i]+cost[i-1];
        };
        get(get,1,0);
        // for(auto it:tmp)cout<<it<<" ";
        int ans=0;
        auto solve=[&](auto&& solve,int i,int req)->void{
            if(2*i>=n && 2*i+1>=n){
                ans+=(req-cost[i-1]);
                return;
            }
            int val=(req-tmp[i]-cost[i-1]);
            ans+=val;
            solve(solve,2*i,req-val-cost[i-1]);
            solve(solve,2*i+1,req-val-cost[i-1]);
        };
        solve(solve,1,mx);
        return ans;
    }
};