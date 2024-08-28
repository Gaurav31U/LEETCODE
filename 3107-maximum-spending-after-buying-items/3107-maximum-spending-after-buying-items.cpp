class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans=0;
        vector<int> temp;
        for(auto i:values){
            for(auto j:i){
                temp.push_back(j);
            }
        }
        sort(temp.begin(),temp.end());
        for(long long i=0;i<temp.size();i++)ans+=(temp[i]*(i+1));
        return ans;
    }
};