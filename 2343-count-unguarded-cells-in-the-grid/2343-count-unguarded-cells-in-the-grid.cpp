class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> tmp(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(auto it:walls){
            tmp[it[0]][it[1]]=-1;
        }
        auto get=[&](auto&& get,int i,int j)->void{
            int x=i,y=j;
            y++;
            while(y<n && tmp[x][y]!=-1 && tmp[x][y]!=2){
                tmp[x][y++]=1;
            }
            x=i+1,y=j;
            while(x<m && tmp[x][y]!=-1 && tmp[x][y]!=2){
                tmp[x++][y]=1;
            }
            x=i-1,y=j;
            while(x>=0 && tmp[x][y]!=-1 && tmp[x][y]!=2){
                tmp[x--][y]=1;
            }
            x=i,y=j-1;
            while(y>=0 && tmp[x][y]!=-1 && tmp[x][y]!=2){
                tmp[x][y--]=1;
            }

            
        };
        for(auto it:guards){
            tmp[it[0]][it[1]]=2;
        }
        for(auto it:guards){
            get(get,it[0],it[1]);
        }
        int ans=0;
        for(auto i:tmp){
            for(auto j:i){
                if(j==0)ans++;
                // cout<<j<<" ";
            }
            // cout<<"\n";
        }
        return ans;
    }
};