class Solution {
public:
    void solve(queue<pair<int,int>> &q, vector<vector<int>>& grid, int &cnt)  {
        bool rot = false;
        if(q.empty()) return;
        queue<pair<int,int>> q2;
        swap(q, q2);
        while(!q2.empty()) {

            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();

            // up
            if(x >= 1) {
                if(grid[x -1][y] == 1) {
                    grid[x -1][y] = 2;
                    rot = true;
                    q.push({x-1, y});
                }
            }
            // left
            if(y >= 1) {
                if(grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    rot = true;
                    q.push({x, y - 1});
                }
            }

            // down
            if(x < grid.size() - 1) {
                if(grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    rot = true;
                    q.push({x+1, y});
                }
            }
            // right
            if(y < grid[0].size() -1 ) {
                if(grid[x][y+1] == 1) {
                    grid[x][y +1] = 2;
                    rot = true;
                    q.push({x, y+1});
                }
            }        
        }

        if(rot) {
            cnt++;           
        }        
        solve(q, grid, cnt);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<int,int>> q;

        for(int i = 0 ; i < grid.size(); i++)  {
            for(int j = 0 ; j< grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});                  
                                 
                } 
            }
        }

        solve(q, grid, cnt);   

        for(int i = 0 ; i < grid.size(); i++)  {
            for(int j = 0 ; j< grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;                
                }                 
            }            
        }
            

        return cnt ;
    }
};