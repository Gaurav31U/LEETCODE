class Solution {
public:
    int dp[100001][10];
    string largestPalindrome(int N, int k) {
       int  n=(N+1)/2;
       int powers[N+1];
       powers[0]=1;
       for(int i=1;i<=N;i++)powers[i]=(powers[i-1]*10)%k;
       memset(dp,-1,sizeof(dp));
       vector<int> res(n+1,-1);
       auto get=[&](auto&& get,int i,int prevmod)->int{
        if(i>=n)return prevmod==0;
        if(dp[i][prevmod]!=-1)return dp[i][prevmod];
        for(int j=9;j>=0;j--){
            int newmod=prevmod;
            if((N&1) && (i==n-1)){
                newmod+=(j*powers[i])%k;
            }else{
                newmod+=(j*powers[i])%k;
                newmod+=(j*powers[N-1-i])%k;
            }
            newmod%=k;
            int ok=get(get,i+1,newmod);
            if(ok){
                res[i]=j;
                break;
            }
        }
        if(res[i]==-1)return dp[i][prevmod]=0;
        return dp[i][prevmod]=1;
       };
       get(get,0,0);
       string ans(N,'0');
       for(int i=0;i<n;i++){
          ans[i]='0'+res[i];
          ans[N-1-i]=ans[i];
       }
       return ans;
    }
};