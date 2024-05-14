class Solution {
public:

    void solve(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int &maxi, int &max_ans) {
        // if(grid[i][j] == 0) return ;

        int row = grid.size();
        int col = grid[0].size();
      
        

        visited[i][j] = 1;
        maxi += grid[i][j];

        // up
        if(i>0 && (!visited[i-1][j] && grid[i-1][j])) {
            
            solve(i -1, j, grid, visited, maxi, max_ans);
        }
        // down
        if(i < row -1 && (!visited[i+1][j] && grid[i+1][j])) {
            
            solve(i + 1, j, grid, visited, maxi, max_ans);
        }
        // left
        if(j>0 && (!visited[i][j-1] && grid[i][j -1])) {
            
            solve(i , j - 1, grid, visited, maxi, max_ans);
        }
        // right
        if(j< col -1 && (!visited[i][j+1] && grid[i][j+1])) {
            solve(i , j + 1, grid, visited, maxi, max_ans);
        }

        max_ans = max(max_ans, maxi);

        maxi -= grid[i][j];
        visited[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ios::sync_with_stdio(0);

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row,vector<int>(col,0));
        
        int ans ;
        int max_ans = 0;
        for(int i = 0 ; i < row; i++) {
            int maxi = 0;
            for(int j = 0; j < col ;j++) {
               if(grid[i][j]) solve(i, j, grid, visited,maxi, max_ans);
            }            
        }

        return max_ans;
    }
};