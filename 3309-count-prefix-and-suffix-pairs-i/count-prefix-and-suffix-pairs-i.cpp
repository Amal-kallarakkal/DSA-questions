class Solution {
public:
    bool check(string sub, string s) {
        if(sub.size() > s.size()) return false;
        int n = sub.size(), m = s.size();
        string prefix = s.substr(0, n), suffix = s.substr(m - n, n);
        if(sub == prefix && sub == suffix) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;

        for(int i = 0 ; i < n - 1; i++) {
            for(int j = i + 1 ; j < n; j++) {
                if(check(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};