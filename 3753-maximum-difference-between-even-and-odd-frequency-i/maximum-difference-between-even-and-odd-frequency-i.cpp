class Solution {
public:
    int maxDifference(string s) {
        int oddmax = 1, evenmin = INT_MAX;
        unordered_map<char, int> mp;

        for(int i = 0 ; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for(auto x : mp) {
            if(x.second%2 == 0) {
                evenmin = min(evenmin, x.second);
            } else oddmax = max(oddmax, x.second);
        }
        
        return oddmax - evenmin;

    }
};