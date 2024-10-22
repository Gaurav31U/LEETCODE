class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int,int> col[9],row[9];
        unordered_map<int,int> grid[3][3];
        vector<vector<char>> ans;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    col[j][board[i][j]-'0']++;
                    row[i][board[i][j]-'0']++;
                    grid[i/3][j/3][board[i][j]-'0']++;
                }
            }
        }
        auto get=[&](auto&& get,int i,int j)->void{
            if(i==9){
                ans=board;
                return;
            }
            if(j==9){
                get(get,i+1,0);
                return;
            }
            if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                    if(row[i][k]==0 && col[j][k]==0 && grid[i/3][j/3][k]==0){
                        row[i][k]++;
                        col[j][k]++;
                        grid[i/3][j/3][k]++;
                        board[i][j]=char('0'+k);
                        get(get,i,j+1);
                        board[i][j]='.';
                        row[i][k]--;
                        col[j][k]--;
                        grid[i/3][j/3][k]--;
                    }
                }
            }else{
                get(get,i,j+1);
            }
        };
        get(get,0,0);
        board=ans;
    }
};