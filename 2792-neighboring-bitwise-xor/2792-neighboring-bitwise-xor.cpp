class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(auto it:derived)ans^=it;
        if(ans!=0)return false;
        return true;
    }
};