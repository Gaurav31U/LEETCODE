static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public: 
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void flip(vector<vector<int>>& mat,int i,int j){
        mat[i][j]^=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int k=0;k<4;k++){
            int ni=dx[k]+i;
            int nj=dy[k]+j;
            if(ni>=0 && nj>=0 && ni<n && nj<m){
                mat[ni][nj]^=1;
            }
        }
    };
    int minFlips(vector<vector<int>>& mat) {
        int ans=INT_MAX;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> fin(n,vector<int>(m,0));
        vector<pair<int,int>> temp;
        int c=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)temp.push_back({i,j});
        map<vector<vector<int>>,int> vis;
        queue<pair<vector<vector<int>>,int>> q;
        q.push({mat,0});
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            auto g=tp.first;
            auto d=tp.second;
            if(g==fin){
                ans=min(ans,d);
                break;
            }
            vis[g]=1;
            for(int k=0;k<temp.size();k++){
                auto tg=g;
                flip(tg,temp[k].first,temp[k].second);
                if(vis.find(tg)==vis.end()){
                    q.push({tg,d+1});
                    vis[tg]++;
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};