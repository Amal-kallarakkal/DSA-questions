class Solution {
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<int>>& grid) {
        int nx, ny;            
        int row = grid.size();
        int col = grid[0].size();
        visited[x][y] = 1;
        for(int i = 0 ; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;

            if(!visited[nx][ny] && grid[nx][ny]) {                
                dfs(nx, ny, visited, grid);
            }

        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
            
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(row, vector<int> (col , 0));

        // boundary dfs
        for(int i = 0 ; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if((i != 0 && i != row - 1)&&(j > 0 && j < col - 1)) continue;
                if(!visited[i][j] && grid[i][j]) {
                    // visited[i][j] = 1;
                    // cout<<"dfs for: "<<i<<", "<<j<<endl;
                    dfs(i, j, visited, grid);
                }
                
            }
        }

     
        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if(!visited[i][j] && grid[i][j]) cnt++;
                // cout<<visited[i][j]<<" ";
            }
        }

        return cnt;
    }
};