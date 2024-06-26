class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        

        vector<vector<int>> nums(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++ ) {
            for(int j = 0 ; j < n; j++) {
                nums[i][j] = matrix[n-j -1][i];
                
            }
        }
        matrix = nums;
    }
};