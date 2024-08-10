class Solution {
public:
    // util array
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int row, int col, vector<vector<int>> &graph, vector<vector<int>> &visited, int &n) {
        visited[row][col] = 1;
        int nx = row , ny = col;
        for(int i = 0; i < 4; i++) {
            nx = row +  dx[i];
            ny = col + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(graph[nx][ny] == 0 && !visited[nx][ny]) {
                dfs(nx, ny, graph, visited, n);
            }

        }
    }

    int regionsBySlashes(vector<string>& grid) {

        int n = 3*grid.size();
        vector<vector<int>> graph(n, vector<int>(n,0));
        vector<vector<int>> visited(n, vector<int>(n,0));

        int ind = 0;   
        int r = 0 , c = 0;

        // make a graph with each slash covering 3*3 matrix
        for(string s: grid) {
            c = 0;
            
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '/') {
                    graph[r][c + 2] = 1;
                    graph[r+1][c+1] = 1;
                    graph[r + 2][c] = 1;
                } else if(s[i] == '\\') {
                    graph[r][c] = 1;
                    graph[r+1][c+1] = 1;
                    graph[r + 2][c + 2] = 1;
                }    
                c += 3;
            }
            r += 3;
        }
        int ans = 0;

        // this is normal dfs ;)
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] == 0 && !visited[i][j]) {
                    ans++;
                    dfs(i, j, graph, visited, n);
                }
            }
        }

        return ans;
    }
};