class Solution {
public:
    int longestPalindrome(string s) {
        ios::sync_with_stdio(0);
        int oddcnt = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        
        for(int i = 0 ; i < s.size(); i++) mp[s[i]]++;
        
        for(auto x: mp) {
            int freq = x.second;
            if(freq %2 == 0) {
                ans += freq;
            }
            else {
                if(freq > 2) ans += (freq/2)*2;
                if(oddcnt == 0) {
                    ans++;
                    oddcnt++;
                }
            }
        }

        return ans;

        
    }
};