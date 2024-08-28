class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int nx, ny;
    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>>& grid) {
        visited[x][y] = 1;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
            if(!visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0; 
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, visited, grid);
                }
            }
        }

        return cnt;
    }
};