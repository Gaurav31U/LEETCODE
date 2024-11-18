class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0)return vector<int>(code.size(),0);
        int n=code.size();
        if(k>0){
            vector<int> ans;
            for(int i=0;i<n;i++){
                int s=0;
                for(int j=i+1;j<i+k+1;j++){
                    s+=code[j%code.size()];
                }
                ans.push_back(s);
            }
            return ans;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i-1;j>(i+k-1);j--){
                s+=code[(j+n)%n];
            }
            ans.push_back(s);
        }
        return ans;
    }
};