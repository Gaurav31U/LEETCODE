class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)return 9;
        if(n==2)return 987;
        string s="";
        for(int i=0;i<n;i++)s+='9';
        long long a=stoi(s);
        long long b=a/10;
        long long ans;
        for(int i=a;i>b;i--){
            string tmp=to_string(i);
            string s=tmp;
            reverse(tmp.begin(),tmp.end());
            s+=tmp;
            long long val=stoll(s);
            long long j=a;
            while(j*j>val){
                if(val%j==0)
                    return val%1337;
                j--;
            }

        }
        return 0;
    }
};