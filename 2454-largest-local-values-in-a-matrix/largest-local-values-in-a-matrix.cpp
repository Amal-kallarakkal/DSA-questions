class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios::sync_with_stdio(0);
        int n = grid.size() - 2;
        vector<vector<int>> res(n, vector<int>(n));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n; j++) {
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