class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt = 0 ; 
        int j, k;
        if(s.size() <=2) return 0;
        for(int i = 0 ; i < s.size() - 2; i++) {
            j = i + 1;
            k = j + 1;
            if(s[i]!= s[j] && s[i]!= s[k] && s[k]!= s[j] ) cnt++;
        }
        return cnt;
    }
};