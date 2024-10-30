class Solution {
public:
    int dp[101][101];
    void build(string s,int i,int j){
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                dp[i][j]=1;
                i--;
                j++;
            }else break;
        }
    }
    int count(string &s,int i,int j){
        int cnt=0;
        while(i<=j){
            if(s[i]!=s[j])cnt++;
            i++;j--;
        }
        return cnt;
    }
    int mx=1e5;
    int palindromePartition(string s, int k) {
        if(s.size()==k)return 0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();i++)build(s,i,i);
        for(int i=1;i<s.size();i++)build(s,i,i+1);
        int n=s.size();
        int realdp[101][101];
        memset(realdp,-1,sizeof(realdp));
        auto get=[&](auto get,int i,int t)->int{
            if(t>n-i || t<0)return mx;
            if(t==(n-i))return 0;
            if(realdp[i][t]!=-1)return realdp[i][t];
            int ans=mx;
            for(int j=i;j<s.size();j++){
                if(dp[i][j]==1){
                    ans=min(ans,get(get,j+1,t-1));
                }else{
                    ans=min(ans,count(s,i,j)+get(get,j+1,t-1));
                }
            }
            return realdp[i][t]=ans;
        };
        return get(get,0,k);
    }
};