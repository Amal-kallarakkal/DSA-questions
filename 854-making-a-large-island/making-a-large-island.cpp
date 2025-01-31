class Solution {
public:
    int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int row, col, ans = 0, nx, ny;
    void dfs(int x, int y, vector<vector<int>> &visited, int &cnt, vector<vector<int>>& grid, int &uid, unordered_map<int, int> &mp) {
        visited[x][y] = 1;
        grid[x][y] = uid;
        cnt++;
        // cout<<"entry: "<<x<<" , "<<y<<" : "<<cnt<<endl;
        for(int i = 0 ; i < 4; i++) {
            nx = x + dxy[i][0];
            ny = y + dxy[i][1];
            if(nx <0 || ny < 0 || nx >= row || ny >= col) continue;
            if(grid[nx][ny] && !visited[nx][ny] ) {                
                dfs(nx, ny, visited, cnt, grid, uid, mp);
            } 
        }
        mp[uid] = cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int cnt = 1, uid = 1, sum;
        vector<vector<int>> visited(row, vector<int> (col));
        unordered_map<int, int> mp;
        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if(grid[i][j] == 1) {
                    cnt = 0;
                    uid++;
                    dfs(i, j, visited, cnt, grid, uid, mp);
                }
            }
        }
        unordered_set<int> set;
        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                if(grid[i][j] == 0) {
                    sum = 0;
                    for(int k = 0 ;k < 4; k++) {
                        nx = i + dxy[k][0];
                        ny = j + dxy[k][1];
                        if(nx <0 || ny < 0 || nx >= row || ny >= col) continue;
                        set.insert(grid[nx][ny]);
                    }
                    for(int s : set ) {
                        sum += mp[s];
                    }
                    set.clear();
                    ans = max(sum + 1, ans);
                }
            }
        }
        
        if(ans == 0 && grid[0][0]) return row*col;
        return ans;
    }
};