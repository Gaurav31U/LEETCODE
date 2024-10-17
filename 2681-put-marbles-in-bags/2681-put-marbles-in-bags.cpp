class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>  temp;
        int n=weights.size();
        for(int i=0;i<n-1;i++)temp.push_back(weights[i]+weights[i+1]);
        long long a1=0,a2=0;
        sort(temp.begin(),temp.end());
        for(int i=0;i<k-1;i++)a1+=temp[i];
        for(int i=temp.size()-1;i>(int)(temp.size()-k);i--)a2+=temp[i];
        return a2-a1;
    }
};