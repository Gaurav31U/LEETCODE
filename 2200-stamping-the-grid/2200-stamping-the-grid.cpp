class Solution {
public:
    int get_sum(int r1, int c1, int r2, int c2, vector<vector<int>>&prefix){
        r1++,c1++,c2++,r2++;
        return prefix[r1 - 1][c1 - 1] + prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1];
    }
    bool possibleToStamp(vector<vector<int>>& grid, int H, int W) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>>prefix(M + 1, vector<int>(N + 1, 0));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] + grid[i][j] - prefix[i][j];
            }
        }
        vector<vector<int>>diff(M + 2, vector<int>(N + 2, 0));
        for(int i = 0; i + H - 1 < M; i++){
            for(int j = 0; j + W - 1 < N; j++){
                if(get_sum(i, j, i + H - 1, j + W - 1, prefix) == 0){
                    diff[i + 1][j + 1] += 1;
                    diff[i + H + 1][j + W + 1] += 1;
                    diff[i + H + 1][j + 1] -= 1;
                    diff[i + 1][j + W + 1] -= 1;
                }
            }
        }
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                diff[i][j] += (diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]);
            }
        }
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0 and diff[i + 1][j + 1] == 0)return false;
            }
        }
        return true;
    }
};