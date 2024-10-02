class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        auto v=arr;
        sort(v.begin(),v.end());
        int i=1;
        for(auto it:v)if(mp[it]==0)mp[it]=i,i++;
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
        
    }
};