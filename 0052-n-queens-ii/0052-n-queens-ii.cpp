class Solution {
public:
    int totalNQueens(int n) {
        vector<string> temp;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++)s+='.';
            temp.push_back(s);
        }
        auto chk=[&](auto&& chk,int i,int j)->bool{
            int x=i-1,y=j-1;
            while(x>=0 && y>=0){
                if(temp[x][y]=='Q')return false;
                x--,y--;
            }
            x=i-1,y=j+1;
            while(x>=0 && y<n){
                if(temp[x][y]=='Q')return false;
                x--,y++;
            }
            x=i-1,y=j;
            while(x>=0){
                if(temp[x][y]=='Q')return false;
                x--;
            }
            return true;
        };
        int cnt=0;
        auto getans=[&](auto&& getans,int i)->void{
            if(i==n){
                cnt++;
                return;
            }
            if(i>n)return;
            for(int j=0;j<n;j++){
                if(chk(chk,i,j)){
                    temp[i][j]='Q';
                    getans(getans,i+1);
                    temp[i][j]='.';
                }
            }
        };
        getans(getans,0);
        return cnt;
    }
};