class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        int dp[2001][2001];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto get,int i,int j)->bool{
            if(i<0){
                if(j<0)return true;
                while(j>=0 && p[j]=='*')j--;
                if(j<0)return true;
                else return false;
            }
            if(i<0 && (j<0 || (j==0 && p[j]=='*')))return true;
            if(j<0 || i<0)return false;
            if(dp[i][j]!=-1)return dp[i][j];
            bool ans=false;
            if(s[i]==p[j]){
                return get(get,i-1,j-1);
            }
            if(p[j]=='*'){
                int t=j,c=0;
                while(t>=0 && p[t]=='*')c++,t--;
                for(int k=i+1;k>=0;k--)
                    ans=max(ans,get(get,k-1,j-c));
            }
            if(p[j]=='?')
                ans=get(get,i-1,j-1);
            return dp[i][j]=ans;
        };
        int j=m-1,c=0;
        while(j>=0 && p[j]=='*')c++,j--;
        return get(get,n-1,m-1) || get(get,n-1,m-c);
    }
};