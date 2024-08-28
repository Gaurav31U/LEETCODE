class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int l=0;
        for(auto it:target){
            if(l<it){
                ans+=abs(it-l);
            }
            l=it;
        }
        return ans;
    }
};