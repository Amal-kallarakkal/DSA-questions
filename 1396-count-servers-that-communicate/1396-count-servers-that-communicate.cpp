class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), alone = 0, total = 0, cnt;
        vector<int> RowSum(row), ColSum(col);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j]) { 
                    RowSum[i]++;
                    total++;
                }
            }
        }
       
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(grid[j][i]) ColSum[i]++;
            }
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] && (RowSum[i] == 1 && ColSum[j] == 1)) total--;
            }
        }
        return total;
    }
};