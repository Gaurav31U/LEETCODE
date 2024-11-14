class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        auto getans=[&](auto&& getans,int val)->bool{
            int k=n,i=0;
            auto temp=quantities;
            while(k>0){
                if(temp[i]>val){
                    temp[i]-=val;
                }else{
                    temp[i]=0;
                    i++;
                    if(i==m)break;
                }
                k--;
            }
            int p=0;
            for(auto it:temp)p+=it;
            return p==0;
        };
        int l=0, r=INT_MAX;
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(getans(getans,mid)){
                ans=min(mid,ans);
                r=mid-1;
            }else l=mid+1;
        } 
        return ans;
    }
};