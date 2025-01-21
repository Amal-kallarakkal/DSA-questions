using ll = long long;
class Solution {
public:
    int row, col;
    ll ans = 0;   
    long long gridGame(vector<vector<int>>& grid) {
        ans, row = grid.size(), col = grid[0].size();
        vector<ll> RowSum(row);
        vector<vector<ll>> top(row, vector<ll>(col)), bottom = top;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) RowSum[i] += grid[i][j];
        } 

        for(int i = 0; i < row - 1; i++) {
            for(int j = 0; j < col; j++) {
                if(j == 0) top[i][j] = RowSum[i] - grid[i][j];
                else top[i][j] = top[i][j-1] - grid[i][j];
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = col - 1; j >= 0; j--) {
                if(j == col-1) bottom[i][j] = RowSum[i] - grid[i][j];
                else bottom[i][j] = bottom[i][j+1] - grid[i][j];
            }
        }  
        ll ColMax;
        for(int i = 0 ; i < row - 1; i++) {
            for(int j = 0; j < col; j++) {
                ColMax = max(top[i][j], bottom[i+1][j]);
                if(j == 0 && i == 0) ans = ColMax;
                ans = min(ans, ColMax);
            }
        }

        return ans;

    }
};