class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)ans.push_back(ans[i-1]^arr[i]);
        vector<int> temp;
        for(auto it:queries){
            if(it[0]==0)
            temp.push_back(ans[it[1]]);
            else temp.push_back(ans[it[1]]^ans[it[0]-1]);
        }
        return temp;
    }
    
};