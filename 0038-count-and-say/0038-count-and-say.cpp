static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            string temp="";
            for(int j=0;j<ans.size();){
                int c=0;
                int e=ans[j];
                while(j<ans.size() && e==ans[j]){
                    j++;
                    c++;
                }
                temp+=to_string(c);
                temp+=char(e);
            }
            ans=temp;
        }
        return ans;
    }
};