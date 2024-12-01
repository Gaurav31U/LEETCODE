class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr)mp[it]++;
        if(mp[0]>=2)return true;
        for(auto it:arr)if(mp[2*it] && it!=0)return true;
        return false;
    }
};