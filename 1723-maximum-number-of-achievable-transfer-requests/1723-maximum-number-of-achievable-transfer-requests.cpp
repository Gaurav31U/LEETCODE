class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=0;
        int m=requests.size();
        for(int i=0;i<(1<<m);i++){
            vector<int> ind(n,0);
            int cnt=0;
            for(int j=0;j<m;j++){
                if((1<<j)&i){
                    ind[requests[j][0]]--;
                    ind[requests[j][1]]++;
                    cnt++;
                }
            }
            int s=0;
            for(auto it:ind)s+=abs(it);
            if(s==0)ans=max(ans,cnt);
        }
        return ans;
    }
};