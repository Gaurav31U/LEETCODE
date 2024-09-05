class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int k=n+rolls.size(),t=k*mean;
        int sum=accumulate(rolls.begin(),rolls.end(),0);
        int l=t-sum;
        vector<int> ans(n,1);
        l-=n;
        if(l<0)return {};
        while(l>0){
            int ch=1;
            for(int i=0;i<n;i++){
                if(ans[i]<6)ans[i]++,l--,ch=0;
                if(l==0)break;
            }
            if(ch)return {};
        }
        return ans;
    }
};