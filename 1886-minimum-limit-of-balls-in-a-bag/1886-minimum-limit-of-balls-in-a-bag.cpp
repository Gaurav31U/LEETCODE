 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
         int ans=INT_MAX;
         int l=1,r=INT_MAX-1;
         while(l<=r){
             int mid=(l+r)/2;
             bool found=false;
             int k=maxOperations;
             for(int i=0;i<nums.size();i++){
                 int p=(nums[i]-1)/mid;
                 k-=p;
             }
             if(k>=0)found=true;
            if(found){
                ans=min(mid,ans);
                r=mid-1;
            }else{
                l=mid+1;
            }
         }
         return l;
    }
};