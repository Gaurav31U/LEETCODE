class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> tmp;
            for(int j=0;j<i+1;j++){
                int val=(j>0?ans[i-1][j-1]:0)+(j<i?ans[i-1][j]:0);
                tmp.push_back(val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};