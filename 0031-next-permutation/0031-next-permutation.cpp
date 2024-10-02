class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end(),greater<int>())){
            reverse(nums.begin(),nums.end());
            return;
        }
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=n-1;i>0;i--){
            pq.push({nums[i],i});
            if(nums[i]>nums[i-1]){
                while(!pq.empty()){
                    if(nums[i-1]<pq.top().first){
                        int e=pq.top().first;
                        for(int j=i;j<n;j++){
                            if(nums[j]==e){
                                swap(nums[j],nums[i-1]);
                                break;
                            }
                        }
                        sort(nums.begin()+i,nums.end());
                        break;
                    }    
                    pq.pop();   
                }
                break;
            }
        }

    }
};