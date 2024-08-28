class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(is_sorted(arr.begin(),arr.end()))return 0;
        int l=0,r=arr.size();
        int ans=r;
        vector<int> pre(arr.size(),0),suf(arr.size(),0);
        pre[0]=1;
        suf.back()=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1])pre[i]=1;
            else break;
        }
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=arr[i+1])suf[i]=1;
            else break;
        }
        while(l<=r){
            int mid=(l+r)/2;
            bool found=false;
            if(suf[mid])found=true;
            if(pre[arr.size()-mid-1])found=true;
            for(int i=0;i<arr.size();i++){
                if(mid+i+1<arr.size() && arr[i]<=arr[mid+i+1]){
                    if(pre[i] && suf[mid+i+1])found=true;
                }
            }
            if(found){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(ans==arr.size()){
            return ans-1;
        }
        return ans;

    }
};