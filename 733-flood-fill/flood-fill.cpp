class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr, sc});
        int row = image.size();
        int col = image[0].size();

        // direction
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int adjx, adjy, x, y;
        int pcolor = image[sr][sc];
        if(pcolor == color) return image;

        image[sr][sc] = color;

        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                adjx = x + dx[i];
                adjy = y + dy[i];
                if(adjx < 0 || adjy<0 || adjx >= row || adjy >= col) continue;
                else {
                    if(image[adjx][adjy] == pcolor) {
                        q.push({adjx, adjy});
                        image[adjx][adjy] = color;
                    }
                }
            }
        }

        return image;
    }
};