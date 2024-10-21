class Solution {
public:
    void solve(int i, string ans, unordered_set<string> &set, string &s, int &maxi) {
        if(i >= s.size()) {
            if(set.size() > maxi) maxi = set.size();
            return;
        }
        ans += s[i];

        if(!set.count(ans)) {
            set.insert(ans);
            solve(i+1, "", set, s, maxi);
            set.erase(ans);
            solve(i+1, ans, set,s, maxi);
        } else {
            solve(i+1, ans, set,s, maxi);
        }
                    
        
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        int maxi = 0;

        solve(0, "", set, s, maxi);
        
        return maxi;
    }
};