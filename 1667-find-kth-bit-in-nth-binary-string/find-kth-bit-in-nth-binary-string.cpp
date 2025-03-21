class Solution {
public:
    string inverse(string s) {
        string is;
        for(int i = 0; i < s.size(); i++) (s[i] == '1')? is += '0': is += '1';
        reverse(is.begin(), is.end());
        return is;
    }

    char findKthBit(int n, int k) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        
        string s = "011";
        if(n <= 2) return s[k - 1];
        for(int i = 3 ; i <= n; i++) {
            if(s.size() >= k) break;
            s += "1" + inverse(s);
        }
        return s[k - 1];
    }
};