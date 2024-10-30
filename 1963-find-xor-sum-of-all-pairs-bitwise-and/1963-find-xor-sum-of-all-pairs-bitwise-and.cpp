class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<long long> freq(32,0);
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<30;j++){
                if(arr2[i]&(1<<j)){
                    freq[j]++;
                }
            }
        }
        int ans=0;
        vector<long long> mfreq(32,0);
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<30;j++){
                if(arr1[i]&(1<<j) && freq[j]>0){
                    mfreq[j]+=freq[j];
                }
            }
        }
        for(int i=0;i<mfreq.size();i++){
            if(mfreq[i]&1){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};