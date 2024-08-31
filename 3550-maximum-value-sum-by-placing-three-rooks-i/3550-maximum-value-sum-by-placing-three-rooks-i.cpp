class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        using pii=pair<int,int>;
        vector<pair<int,int>> temp[n];
        for(int i=0;i<n;i++){
            priority_queue<pii,vector<pii>,greater<pii>> pq;
            for(int j=0;j<m;j++){
                pq.push({board[i][j],j});
                if(pq.size()>3)pq.pop();
            }
            while(!pq.empty()){
                temp[i].push_back(pq.top());
                pq.pop();
            }
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    for(auto [v1,c1]:temp[i]){
                        for(auto [v2,c2]:temp[j]){
                            if(c1==c2)continue;
                            for(auto [v3,c3]:temp[k]){
                                if(c1==c3 || c2==c3)continue;
                                ans=max(ans,0ll+v1+v2+v3);
                            }
                        }
                    }
                }
            }
        }
        return ans;

    }
};