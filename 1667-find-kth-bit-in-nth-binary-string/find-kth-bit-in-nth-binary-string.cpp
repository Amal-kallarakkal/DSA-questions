class Solution {
public:
    string inverse(string s) {
        string is;
        for(int i = 0; i < s.size(); i++) (s[i] == '1')? is += '0': is += '1';
        reverse(is.begin(), is.end());
        return is;
    }

    char findKthBit(int n, int k) {
        string s = "011";
        if(n <= 2) return s[k - 1];
        for(int i = 3 ; i <= n; i++) {
            s += "1" + inverse(s);
        }
        // cout<<s;
        return s[k - 1];
    }
};