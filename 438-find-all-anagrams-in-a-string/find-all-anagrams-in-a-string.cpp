class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26, 0);
        vector<int> ans;
        int win = p.size(), n = s.size(), j ;
        if(win > n) return ans;
        for(int i = 0 ; i < win; i++) {
            mp[p[i] - 'a']++;
        }
               
        for(int i = 0; i < n - win + 1; i++) {
            vector<int> temp(26, 0);
            if(mp[s[i] - 'a']) {
                for(int j = i; j < i + win; j++) temp[s[j] - 'a']++;
                if(temp == mp) ans.push_back(i);
            }
        }
        return ans;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();