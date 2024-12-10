class Solution {
public:
    int possible(int mid, string &s) {
        int cnt = 0, curr;
        unordered_map<char, int> mp;
        if(mid == 1) {
            for(int i = 0 ; i <= s.size(); i++) {
                mp[s[i]]++;
                if(mp[s[i]] > 2) return true;
            }
            return false;
        }
        for(int i = 0 ; i < s.size(); i++) {
            curr = 0;
            for(int j = i ; j < i + mid - 1; j++) {
                if(s[j] == s[j+1]) curr++;
                else break;
            }
            if(curr >= mid - 1) {                
                mp[s[i]]++;
                if(mp[s[i]]>= 3) return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int ans = -1, h = s.size(), l = 0, mid;
        while(l <= h) {
            mid = (l + h)/2;
            // cout<<mid<<endl;
            if(possible(mid, s)) {
                ans = mid;
                l = mid + 1;
            } else h = mid - 1;
        }
        if(ans == 0) return -1;

        return ans;        
    }
};