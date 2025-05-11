class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int s=0;
        for(auto it:arr){
            s+=it&1;
            if(s>2)return true;
            if((it&1)==0)s=0;
        }
        return false;
    }
};