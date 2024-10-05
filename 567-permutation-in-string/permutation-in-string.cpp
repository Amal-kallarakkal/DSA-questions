class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s2.size() < n) return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> temp;
        string t = "";
        
        for(int i = 0 ; i < n ; i++) mp[s1[i]]++;

        for(int i = 0 ; i < s2.size() - n + 1; i++) {
            temp.clear();
            if(mp.count(s2[i])) {
                t = s2.substr(i, n);
                for(int i = 0 ; i < n ; i++) temp[t[i]]++;
                if(temp == mp) return true;
            }
        }

        return false;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();