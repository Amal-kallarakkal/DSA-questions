class Solution {
public:
    int minLength(string s) {
        int i = 0;
        string t, pre, suf;
        while(i < s.size()) {
            t = s.substr(i, 2);
            // cout<<t<<endl;
            if(t == "AB" || t == "CD") {
                pre = s.substr(0 , i);
                suf = s.substr(i+2, s.size() - i - 2);\
                // cout<<pre<<" + "<<suf<<endl;
                s = pre + suf;
                // cout<<s<<endl;
                i = 0;
                continue;
            }
            i++;
        }
        return s.size();
    }
};