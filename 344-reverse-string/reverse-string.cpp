class Solution {
public:
    void reverseString(vector<char>& s) {
        ios::sync_with_stdio(0);
        int n = s.size() - 1;
        int i = 0;
        while(i < n) {
            swap(s[i++],s[n--]);
        }
        
    }
};