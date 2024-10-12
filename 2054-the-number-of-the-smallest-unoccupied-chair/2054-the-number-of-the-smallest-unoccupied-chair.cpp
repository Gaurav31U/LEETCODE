class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<array<int,3>> vi;
        for(int i=0;i<n;i++){
            vi.push_back({times[i][0],1,i});
            vi.push_back({times[i][1],-1,i});
        }
        sort(vi.begin(),vi.end());
        vector<int> vis(n,-1);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)pq.push(i);
        for(int i=0;i<vi.size();i++){
            auto tp=vi[i];
            if(tp[1]==1){
                int s=pq.top();
                vis[tp[2]]=s;
                if(tp[2]==targetFriend)return s;
                pq.pop();
            }else{
                int s=vis[tp[2]];
                pq.push(s);
            }
        }
        return n;
    }
};