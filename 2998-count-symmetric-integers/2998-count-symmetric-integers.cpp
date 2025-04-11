class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string t=to_string(i);
            if(t.size()%2==1)continue;
            int n=t.size();
            int s=0;
            for(int j=0;j<n/2;j++)s+=(t[j]-'0');
            for(int j=n/2;j<n;j++)s-=(t[j]-'0');
            if(s==0)ans++;
        }
        return ans;
    }
};