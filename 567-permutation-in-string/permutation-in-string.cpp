class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s2.size() < n) return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> temp;
        
        for(int i = 0 ; i < n ; i++) mp[s1[i]]++;

        for(int i = 0 ; i < s2.size() - n + 1; i++) {
            temp.clear();
            if(mp.count(s2[i])) {                
                for(int j = i ; j < i+ n ; j++) {
                    if(!mp.count(s2[j])) break;
                    temp[s2[j]]++;
                }
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