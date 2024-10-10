const long M=1e9+7;
int a[23], b[23], init=1;
long dp[23][401];
class Solution {
public:
    long dfs(int len, int sum) {
        if(len<0 || sum<0)
            return 0;
        if(dp[len][sum]>=0)
            return dp[len][sum];
        if(len==0 || sum==0)
            return dp[len][sum]=1;
        long ans=0;
        for(int i=0; i<=9; ++i) {
            ans+=dfs(len-1, sum-i);
        }
        return dp[len][sum]=ans%M;
    }
    long helper(int * dgt, int sum) {
        long ans=0;
        for(int i=0, j; i<23 && sum>=0; ++i) {
            for(j=0; j<dgt[i] && sum>=0; ++j, ans+=dfs(22-i, sum--)) {}
        }
        return (ans+(sum>=0))%M;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(init) {
            init=0;
            for(int i=0, j; i<23;  ++i) {
                for(j=0; j<=400; dp[i][j++]=-1) {}
            }
        }
        for(int i=num1.size()-1, j=22, carry=1; j>=0; --j) {
            a[j]=i>=0? num1[i--]-'0' : 0;
            if(a[j]<carry) {
                a[j]+=10-carry;
                carry=1;
            } else {
                a[j]-=carry;
                carry=0;
            }
        }
        for(int i=num2.size()-1, j=22; j>=0; b[j--]=i>=0? num2[i--]-'0' : 0) {}
        return (helper(b, max_sum)+M-helper(b, min_sum-1)+M-helper(a, max_sum)+helper(a, min_sum-1))%M;
    }
};