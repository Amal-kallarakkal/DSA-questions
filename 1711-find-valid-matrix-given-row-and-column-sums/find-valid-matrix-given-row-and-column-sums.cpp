class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();

        vector<vector<int>> ans(row, vector<int> (col));
        for(int i = 0; i < row; i++) {
            ans[i][0] = rowSum[i];
        }
        int  sum;
        for(int i = 0 ; i < col; i++) {
            sum = 0;
            for(int j = 0; j < row; j++)  {
                sum += ans[j][i];
                if(sum > colSum[i]) {
                    ans[j][i+1] = sum - colSum[i];
                    ans[j][i] -= ans[j][i+1];
                    sum = colSum[i];
                }
            }          
        }
        return ans;
    }
};