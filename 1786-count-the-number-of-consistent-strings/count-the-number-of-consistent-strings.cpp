class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0 ,cnt2;
        set<char> set;
        for(int  i = 0 ; i < allowed.size(); i++) {
            set.insert(allowed[i]);
        }

        for(auto x : words) {
            cnt2 = 0;
            for(int i = 0 ; i < x.size(); i++) {
                if(!set.count(x[i])) break;
                cnt2++;
            }
            if(cnt2 >= x.size()) cnt++;
        }

        return cnt;
    }
};


static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();