class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> arr1Sorted, arr2Sorted, arr1, arr2;
        nums.insert(nums.begin(), 0);
        int n=nums.size();
        arr1Sorted.push_back(nums[1]);
        arr2Sorted.push_back(nums[2]);
        arr1.push_back(nums[1]);
        arr2.push_back(nums[2]);
        for(int i=3; i<n; i++) {
            auto ub1=upper_bound(arr1Sorted.begin(), arr1Sorted.end(), nums[i]);
            auto ub2=upper_bound(arr2Sorted.begin(), arr2Sorted.end(), nums[i]);
            int greater1=arr1Sorted.end()-ub1;
            int greater2=arr2Sorted.end()-ub2;
            if(greater1>greater2 || (greater1==greater2 && arr1Sorted.size()<=arr2Sorted.size())) {
                arr1Sorted.insert(ub1, nums[i]);
                arr1.push_back(nums[i]);
            }
            else {
                arr2Sorted.insert(ub2, nums[i]);
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};