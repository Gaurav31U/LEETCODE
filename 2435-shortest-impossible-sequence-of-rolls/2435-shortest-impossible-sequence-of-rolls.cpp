class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=rolls.size()-1;i>=0;i--){
            mp[rolls[i]]++;
            if(mp.size()==k){
                cnt++;
                mp.clear();
            }
        }
        return cnt+1;
    }
};