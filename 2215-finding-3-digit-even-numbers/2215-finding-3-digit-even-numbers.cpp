class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n=digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || k==j || i==k || digits[i]==0)continue;
                    if(digits[k]%2==0)
                        ans.insert(digits[i]*100+digits[j]*10+digits[k]);
                }
            }
        }
        vector<int>temp;
        for(auto it:ans)temp.push_back(it);
        return temp;
    }
};