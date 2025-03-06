class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(n*n + 1, 0);
        vector<int> res(2);
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n ; j++) {
               ans[grid[i][j]]++;
            }
        }
    
        for(int i = 1 ; i <= n*n ; i++) {
            if(ans[i] == 2) res[0] = i;
            if(ans[i] == 0) res[1] = i;
        }
        return res;
    }
};