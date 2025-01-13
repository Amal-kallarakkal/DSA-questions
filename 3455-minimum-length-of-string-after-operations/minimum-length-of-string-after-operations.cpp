class Solution {
public:
    int minimumLength(string s) {
        map<char, int> mp;
        int n = s.size(), ans = 0;
        if(n < 3) return n;
        for(char i : s) mp[i]++;
        for(auto x : mp) {
            if(x.second > 2) {
                if(x.second&1) {
                    ans += x.second - 1;
                } else ans += x.second - 2;
            }
        }

        return n - ans;

    }
};