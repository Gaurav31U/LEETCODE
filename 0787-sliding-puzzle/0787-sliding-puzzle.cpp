static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string tostring(vector<vector<int>> temp){
        string s="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s+=to_string(temp[i][j]);
            }
        }
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string,int> vis;
        string f="123450";
        int ans=INT_MAX;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1}; 
        queue<pair<array<int,3>,vector<vector<int>> > > q;
        for(int i=0;i<2;i++){
          for(int j=0;j<3;j++){
            if(board[i][j]==0){
              q.push({{i,j,0},board});
            }
          }
        }
        while(!q.empty()){
          auto tp=q.front();
          q.pop();
          auto state=tp.second;
          int i=tp.first[0];
          int j=tp.first[1];
          int d=tp.first[2];
          auto s=tostring(state);
          vis[s]=1;
          if(s==f){
            ans=min(ans,d);
          }
          for(int k=0;k<4;k++){
            int ni=dx[k]+i;
            int nj=dy[k]+j;
            if(ni>=0 && nj>=0 && ni<2 && nj<3){
              swap(state[i][j],state[ni][nj]);
              auto st=tostring(state);
              if(vis.find(st)==vis.end()){
                  q.push({{ni,nj,d+1},state});
              }else{
                  if(st==f){
                    ans=min(ans,d+1);
                  }
              }
              swap(state[i][j],state[ni][nj]);
            }
          }
        }
        if(ans==INT_MAX)return -1;
        return ans;

    }
};