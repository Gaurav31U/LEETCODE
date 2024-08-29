class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> a,b;
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++)a.push_back(nums[i]);
        for(int i=n/2;i<n;i++)b.push_back(nums[i]);
        vector<int> temp1,temp2;
        for(int i=0;i<(1<<a.size());i++){
            int s=0;
            for(int j=0;j<a.size();j++){
                if(i&(1<<j)){
                    s+=a[j];
                }
            }
            ans=min(ans,abs(s-goal));
            temp1.push_back(s);
        }
        for(int i=0;i<(1<<b.size());i++){
            int s=0;
            for(int j=0;j<b.size();j++){
                if(i&(1<<j)){
                    s+=b[j];
                }
            }
            ans=min(ans,abs(s-goal));
            temp2.push_back(s);
        }
        sort(temp2.begin(),temp2.end());
        for(int i=0;i<temp1.size();i++){
            auto tp=lower_bound(temp2.begin(),temp2.end(),goal-temp1[i]);
            if(tp!=temp2.end())
                ans=min(ans,abs(*tp+temp1[i]-goal));
            if(tp!=temp2.begin())--tp;
            ans=min(ans,abs(*tp+temp1[i]-goal));
        }
        return ans;
    }
};