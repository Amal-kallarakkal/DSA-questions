class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rows = grid.size() - 2;
        int column = grid[0].size() - 2;
        vector<vector<int>> res(rows, vector<int>(column));

        for(int i = 0 ; i < rows ; i++) {
            for(int j = 0 ; j < column; j++) {
                int maxi = grid[i][j];
                for(int a = i; a< i+3; a++) {
                    
                    for(int b = j; b< j+3; b++) {
                        maxi = max(maxi, grid[a][b]);
                    }
                }
                res[i][j] = maxi;
            }

        }

        return res;
    }
};