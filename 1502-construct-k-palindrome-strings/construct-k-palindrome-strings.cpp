class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size(), oddcnt = 0;

        if(k > n) return false;
        if(k == n) return true;
        map<char, int> mp;
        for(int i = 0 ; i < n; i++) {
            mp[s[i]]++;
        }
        for(auto x : mp) {
            if(x.second%2) oddcnt++;
        }
        if(oddcnt>k) return false;
        return true;
    }
};