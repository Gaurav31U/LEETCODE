static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int arr[30]={0};
        for(int i=n-1;i>=0;i--){
            int a=nums[i];
            int j=0;
            int mx=i;
            while(j<30){
             if(a && a&1) arr[j]=i;
             mx=max(mx,arr[j]);
             if(a)
             a/=2;
             j++;
            }
            ans[i]=mx-i+1;
            
        }
        return ans;

    }
};