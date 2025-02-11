class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "", temp = "";
        int n = part.size();
        if(n > s.size()) return s;
        for(int i = 0 ;i < s.size(); i++ ) {
            temp = s.substr(i, n);
            if(temp == part) {
                // cout<<
                // if(i + n >= s.size()) return s.substr(0, i);
                // cout<<" + "<<s.substr(i + n, s.size() - n) ;
                ans = s.substr(0, i) + s.substr(i + n, s.size() - n);
                // cout<<ans<<endl;
                return removeOccurrences(ans, part);
            }
        }
        return s;
    }
};