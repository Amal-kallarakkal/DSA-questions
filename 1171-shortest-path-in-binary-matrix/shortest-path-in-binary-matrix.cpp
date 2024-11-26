class Solution {
public:
    int dxy[8][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
    int nx, ny;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), x, y, cnt = 0;
        pair<int, int> top;
        vector<vector<int>> visited(n, vector<int> (n));
        if(grid[0][0]) return -1;
        q.push({0, 0});
        q.push({-1, -1});
        visited[0][0] = 1;
        while(!q.empty()) {
            top = q.front();
            q.pop();
            x = top.first, y = top.second;
            if(x == -1 && !q.empty()) {
                q.push({-1, -1});
                cnt++;
            } else if(x != -1){
                if(x == n -1 && y == n-1) return cnt + 1;
                for(int i = 0 ; i < 8; i++) {
                    nx = x + dxy[i][0];
                    ny = y + dxy[i][1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
                    if(!grid[nx][ny] && !visited[nx][ny]) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                // visited[x][y] = 0;
            }            
        }
        return -1;
    }
};