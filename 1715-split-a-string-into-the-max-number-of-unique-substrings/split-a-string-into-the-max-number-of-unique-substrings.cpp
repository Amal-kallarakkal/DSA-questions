class Solution {
public:
    void solve(int i, string ans, unordered_set<string> &set, string &s, int &maxi, int cnt) {
        // return if cant reach maxi
        if(maxi >= cnt + (s.size() - i)) return;
        if(i >= s.size()) {
            maxi = max(cnt, maxi);
            return;
        }
        ans += s[i];

        if(!set.count(ans)) {
            set.insert(ans);
            solve(i+1, "", set, s, maxi , cnt + 1);
            set.erase(ans);
            solve(i+1, ans, set,s, maxi, cnt);
        } else {
            solve(i+1, ans, set,s, maxi, cnt);
        }                  
        
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        int maxi = 0;
        solve(0, "", set, s, maxi, 0);        
        return maxi;
    }
};