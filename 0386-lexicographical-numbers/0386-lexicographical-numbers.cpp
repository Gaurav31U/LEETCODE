static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        auto dfs=[&](auto&& dfs,string s)->void{
            int num=stoi(s);
            if(num>n)return;
            ans.push_back(num);
            for(int i=0;i<=9;i++){
                dfs(dfs,s+to_string(i));
            }
        }; 
        for(int i=1;i<=9;i++){
            dfs(dfs,to_string(i));
        }
        return ans;
    }
};