class Solution {

public:
    static const int m = 1000000007;
    int solve(int n, int idx, int ab, int lv, vector<vector<vector<int>>> &dp) {
       
        if(idx >= n) return 1;

        if(dp[idx][ab][lv] != -1) {
            return dp[idx][ab][lv];
        }
      
        
        // include A
        int a = (ab == 0)? solve(n, idx + 1, ab + 1, 0, dp) : 0;

        // include leave
        int l = (lv == 2)? 0 : solve(n, idx + 1, ab, lv + 1, dp);

        // include p
        int p = solve(n, idx + 1, ab, 0, dp);

        int total =  ((a + l )%m + p)%m;

        dp[idx][ab][lv] = total;

        return total;
    
    }

    int checkRecord(int n) {
        // dp[i][a][lv]
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0,0, dp);

        
    }
};