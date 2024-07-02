#pragma GCC optimize("OFast")
class Solution {
public:
    
    int solve(string &s, int &k, char &C, int &maxi) {
        int cnt = 0;
        
        // for maximum continous char C(any unique char in s)
        int j = 0;
        for(int i = 0 ; i < s.size() - maxi; i++) {
            while(j <  s.size() && cnt <= k ) {
                if(s[j] != C) cnt++;
                if(cnt > k) {
                    cnt--;
                    
                    break;
                }
                j++;
            }
            
            maxi = max(maxi, j - i);            
            if(s[i] != C) cnt--;       
            
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        unordered_set<char> set;
        for(int i = 0 ; i < s.size(); i++) set.insert(s[i]);
        int maxi = 0;
        for(auto x: set) {
            maxi = max(maxi, solve(s, k, x, maxi));
        }
        return maxi;
    }
};