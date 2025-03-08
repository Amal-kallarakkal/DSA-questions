class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size(), ans = INT_MAX, cnt = 0, j;

        for(int i = 0 ; i < k ; i++) {
            if(s[i] == 'W') cnt++;
        }
        ans = cnt;
        for(int i = 0; i < n - k; i++) {
            j = i + k;
            if(s[i] == 'W') cnt--;
            if(s[j] == 'W') cnt++;
            // cout<<i<<" : "<<cnt<<endl;
            ans = min(ans, cnt);
        }
        return ans;
    }
};