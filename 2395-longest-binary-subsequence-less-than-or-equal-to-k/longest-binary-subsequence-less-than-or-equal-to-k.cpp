class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int ans = 0;
        long long limit = 0, n = s.size() - 1;

        for(int i = n ; i >= 0; i--) {
            if(s[i] == '0') ans++;
            else {
                if(n - i <= 60) limit += pow(2, n - i);
                else limit = INT_MAX;
                if(limit <= k) ans++;
            }
        }
        return ans;
    }
};