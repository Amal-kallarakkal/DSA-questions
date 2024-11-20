class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<int, int> mp;
        int maxi = 0, n = s.size(), l = 0, r = l, ans;

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        if(!(mp['a'] >= k && mp['b'] >= k && mp['c'] >= k)) return -1;
        while(l < n && r < n) {
            // r = l;
            if(r < l) r = l;
            while(r < n &&( mp['a'] >= k && mp['b'] >= k && mp['c'] >= k)) {
                mp[s[r]]--;
                if(mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) maxi = max(maxi, r - l + 1);
                r++;
            }
            // cout<<"l: "<<l<<", r: "<<r<<endl;
            // cout<<maxi<<endl;
            // maxi = max(maxi, r - l + 1);
            mp[s[l++]]++;
        }
        // cout<<maxi<<endl;
        ans = n - maxi;

        return ans;
    }
};