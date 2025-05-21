class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int r = matrix.size(), c = matrix[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        } 
        for(int x: row) {
            for(int j = 0; j < c; j++) matrix[x][j] = 0;
        }

        for(int x: col) {
            for(int i = 0; i < r; i++) matrix[i][x] = 0;
        }
    }
};