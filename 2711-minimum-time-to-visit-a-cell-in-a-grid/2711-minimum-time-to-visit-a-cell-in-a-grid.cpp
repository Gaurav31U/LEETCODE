class Solution {
public:
    int minimumTime(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        if(a[0][1]>1 && a[1][0]>1)return -1;
        set<vector<int>> q;
        q.insert({0,0,0});
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=0;
        vector<int> dir{0,1,0,-1,0};
        while(!q.empty()){
            vector<int> c=*(q.begin());
            q.erase(q.begin());
            int x=c[1],y=c[2];
            int time=c[0];
            if(x==(m-1) && y==(n-1))return time;
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(min(nx,ny)>=0 && nx<m && ny<n){
                    int d=a[nx][ny]-time;
                    if(time+1>=a[nx][ny] && time+1<dp[nx][ny]){
                        q.erase({dp[nx][ny],nx,ny});
                        dp[nx][ny]=time+1;
                        q.insert({dp[nx][ny],nx,ny});
                    }else if(time+1<a[nx][ny]){
                        int d=a[nx][ny]-time;
                        if(d%2){
                            if(a[nx][ny]<dp[nx][ny]){
                                q.erase({dp[nx][ny],nx,ny});
                                dp[nx][ny]=a[nx][ny];
                                q.insert({dp[nx][ny],nx,ny});
                            }
                        }
                        else{
                            if(a[nx][ny]+1<dp[nx][ny]){
                                q.erase({dp[nx][ny],nx,ny});
                                dp[nx][ny]=a[nx][ny]+1;
                                q.insert({dp[nx][ny],nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};