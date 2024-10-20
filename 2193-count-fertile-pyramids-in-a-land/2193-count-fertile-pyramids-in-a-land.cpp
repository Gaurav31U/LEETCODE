class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        auto tmp=grid;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                tmp[i][j]+=tmp[i][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int x1=i+1,y1=j-1;
                    int x2=i+1,y2=j+1;
                    int cnt=1,s=3;
                    while(x1<n && x2<n && y1>=0 && y2<m){
                        int a=tmp[x2][y2];
                        int b=(y1>0?tmp[x1][y1-1]:0);
                        if(a-b==s && (y2-y1+1)==s){
                            cnt++;
                            s+=2;
                        }
                        x1++,y1--,x2++,y2++;
                    }
                    ans+=(cnt-1);

                    x1=i-1,y1=j-1;
                    x2=i-1,y2=j+1;
                    cnt=1,s=3;
                    while(x1>=0 && x2>=0 && y1>=0 && y2<m){
                        int a=tmp[x2][y2];
                        int b=(y1>0?tmp[x1][y1-1]:0);
                        if(a-b==s && (y2-y1+1)==s){
                            cnt++;
                            s+=2;
                        }
                        x1--,y1--,x2--,y2++;
                    }
                    ans+=(cnt-1);

                }
            }
        }
        return ans;
    }
};