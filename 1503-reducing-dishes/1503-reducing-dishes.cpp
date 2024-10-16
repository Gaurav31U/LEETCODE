class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int maxval=0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=(satisfaction[j]*(j-i+1));
            }
            maxval=max(maxval,s);
        }
        return maxval;
    }
};