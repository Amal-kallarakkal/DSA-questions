class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        if(n > s.size()) return s;
        for(int i = 0 ;i < s.size(); i++ ) {
            if(s.substr(i, n) == part) {
                return removeOccurrences(s.substr(0, i) + s.substr(i + n, s.size() - n), part);
            }
        }
        return s;
    }
};