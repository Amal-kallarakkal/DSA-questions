class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &board, int &row, int &col) {
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = r + dx[i], ny = c + dy[i];
            if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                    
            if(!vis[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, vis, board, row, col);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int> (col, 0));
        for(int i = 0 ; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if((i != 0 && i != row - 1) && (j > 0 && j < col - 1) ) continue;
                else if(board[i][j] == 'O') {
                    if(visited[i][j] == 0) {
                        dfs(i, j, visited, board, row, col);
                    }
                }
            }
        }

        for(int i = 0 ;i < row; i++) {
            for(int j = 0 ; j < col ; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
                // cout<<visited[i][j]<<" ";
            }
        }

    }
};