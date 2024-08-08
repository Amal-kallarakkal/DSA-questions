class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        int cnt = 0;
        vector<vector<int>> ans(rows * cols, vector<int>(2));
        
        int i = rStart;
        int j = cStart;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;  // start with right direction
        int steps = 1;

        ans[cnt++] = {i, j};

        while (cnt < rows * cols) {
            for (int k = 0; k < 2; ++k) {  // repeat for 2 turns for each step increment
                for (int step = 0; step < steps; ++step) {
                    i += direction[d][0];
                    j += direction[d][1];
                    if (i >= 0 && j >= 0 && i < rows && j < cols) {
                        ans[cnt++] = {i, j};
                    }
                }
                d = (d + 1) % 4;  // change direction
            }
            steps++;  // increment step size after two directions
        }

        return ans;
    }
};