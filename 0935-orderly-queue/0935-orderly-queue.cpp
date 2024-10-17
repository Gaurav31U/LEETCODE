class Solution {
public:
    void leftrotate(string &s, int d){
        reverse(s.begin(), s.begin()+d);
        reverse(s.begin()+d, s.end());
        reverse(s.begin(), s.end());
    }
    void rightrotate(string &s, int d){
        leftrotate(s, s.length()-d);
    }
    string orderlyQueue(string s, int k) {
        vector<string> ans;
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }else{
            for(int i=0;i<=s.size();i++){
                rightrotate(s,1);
                ans.push_back(s);
            }
            sort(ans.begin(),ans.end());
        }
        return ans[0];
    }
};