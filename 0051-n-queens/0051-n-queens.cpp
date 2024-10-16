class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        for(int i=0;i<n;i++){
            string t="";
            for(int j=0;j<n;j++)t+='.';
            temp.push_back(t);
        }
        auto isvalid=[&](auto&& isvalid,int i,int j)->bool{
            int ni=i,nj=j;
            for(;ni>=0;ni--)if(temp[ni][nj]=='Q')return false;
            ni=i;
            for(;ni>=0 && nj>=0;ni--,nj--)if(temp[ni][nj]=='Q')return false;
            ni=i,nj=j;
            for(;ni>=0 && nj<n;ni--,nj++)if(temp[ni][nj]=='Q')return false;
            return true;
        };
        auto getans=[&](auto&& getans,int k)->void{
            if(k==n){
                ans.push_back(temp);
                return;
            }
            for(int i=0;i<n;i++){
                if(isvalid(isvalid,k,i)){
                    temp[k][i]='Q';
                    getans(getans,k+1);
                    temp[k][i]='.';
                }
            }
        };
        getans(getans,0);
        return ans;

    }
};