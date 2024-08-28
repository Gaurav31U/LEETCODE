class Solution {
public:
    int seg[1201];
    int arr[301];
    void build(int s,int i,int j){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*s+1,i,mid);
        build(2*s+2,mid+1,j);
        seg[s]=max(seg[2*s+1],seg[2*s+2]);
    }
    int query(int s,int i,int j,int qi,int qj){
        if(j<qi || i>qj){
            return INT_MIN;
        }
        if(i>=qi && j<=qj){
            return seg[s];
        }
        int mid=(i+j)/2;
        int l=query(2*s+1,i,mid,qi,qj);
        int r=query(2*s+2,mid+1,j,qi,qj);
        return max(l,r);
    }
    int minDifficulty(vector<int>& job, int d) {
        if(d>job.size())return -1;
        for(int i=0;i<job.size();i++){
            arr[i]=job[i];
        }
        int mx=1e5;
        int n=job.size();
        build(0,0,n-1);
        int dp[301][11];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int k)->long long{
            if(dp[i][k]!=-1)return dp[i][k];
            if(i>=n)return mx;
            if(k==1)return query(0,0,n-1,i,n-1);
            if(n-i<k)return mx;
            long long ans=mx;
            for(int j=i;j<n;j++){
                ans=min(ans,query(0,0,n-1,i,j)+get(get,j+1,k-1));
            }
            return dp[i][k]=ans;
        };
        return get(get,0,d);
    }
};