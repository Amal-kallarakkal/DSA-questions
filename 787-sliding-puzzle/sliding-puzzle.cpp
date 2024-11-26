class Solution {
public:
    int dxy[4][2] = {{-1, 0}, {0, -1}, {1, 0},{0, 1}}, nx, ny;
    int slidingPuzzle(vector<vector<int>>& board) {
        set<vector<vector<int>>> visited;
        vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}}, top;
        if(board == ans) return 0;
        queue<pair<pair<int, int>, vector<vector<int>>>> q;
        int cnt = 0, x, y;
        pair<int, int> p;
        for(int i = 0 ; i < 2; i++) for(int j = 0; j < 3; j++) if(board[i][j] == 0) p = {i, j};
        q.push({p, board});
        q.push({{-1, -1}, {}});
        visited.insert(board);

        while(!q.empty() && cnt < 36) {
            
            top = q.front().second;
            x = q.front().first.first;
            y = q.front().first.second;
            q.pop();

            if(x == 1 && y == 2) {
                if(top == ans) return cnt;
            }
            if(x == -1) {
                cnt++;
                q.push({{-1, -1}, {}});
                continue;
            }
            for(int i = 0 ; i < 4 ; i++) {
                nx = x + dxy[i][0];
                ny = y + dxy[i][1];
                if(nx < 0 || ny < 0 || nx >= 2 || ny >= 3) continue;
                
                swap(top[x][y], top[nx][ny]);
                if(!visited.count(top)) {
                    visited.insert(top);
                    q.push({{nx, ny}, top});
                }
                swap(top[x][y], top[nx][ny]);
            }

        }
        return (cnt >= 36)? -1 : cnt;
    }
};