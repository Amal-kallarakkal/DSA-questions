using ll = long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0;
        int mini = INT_MAX, n = matrix.size(), neg = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if(matrix[i][j] < 0) {
                    neg++;
                    sum -= matrix[i][j];
                }
                else sum += matrix[i][j];
                mini= min(abs(matrix[i][j]), mini);
            }
        }
        if(neg %2) {
            sum -= 2*mini;
        } 
        return sum;
    }
};