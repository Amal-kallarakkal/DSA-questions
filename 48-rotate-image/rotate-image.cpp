class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        

        vector<vector<int>> nums(n, vector<int>(n, 0));
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

        for(int i = 0; i < n; i++ ) {
            for(int j = 0 ; j < n; j++) {
                cout<<matrix[i][j]<<" ";
            }cout<<endl;
        }
        // matrix = nums;
    }
};

// 1 2
// 3 4 

// 2 1
// 3 4

// 4 1 
// 3 2

// 3 1
// 4 2