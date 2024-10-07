class Solution {
public:
    int minLength(string s) {
        int i = 0;
        string t, pre, suf;
        while(i < s.size()) {
            t = s.substr(i, 2);
            if(t == "AB" || t == "CD") {
                pre = s.substr(0 , i);
                suf = s.substr(i+2, s.size() - i - 2);\
                s = pre + suf;
                i = 0;
                continue;
            }
            i++;
        }
        return s.size();
    }
};

const static int speedup = []() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
