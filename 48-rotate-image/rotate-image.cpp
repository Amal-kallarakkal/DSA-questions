#pragma GCC optimize("OFast")
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        int n = matrix[0].size();     
        int k = 0;
        if(n%2) k = 1;
        for(int i = 0; i < n/2 ; i++ ) {
            for(int j = 0 ; j < n/2 + k; j++) {

                if(i == j ) {
                    swap(matrix[i][j], matrix[i][n-j -1]);
                    swap(matrix[i][j], matrix[n-j -1][n-i-1]);
                    swap(matrix[i][j], matrix[n-j -1][i]);                    
                }
                else {
                    swap(matrix[i][j], matrix[j][n- 1- i]);
                    swap(matrix[i][j], matrix[n- 1- i][n- 1- j]);
                    swap(matrix[i][j], matrix[n- 1- j][i]);
                }
                
            }
        }

       
    }
};

