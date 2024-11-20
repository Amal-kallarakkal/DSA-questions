class Solution {
public:
    int takeCharacters(string s, int k) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int ca = 0, cb = 0, cc = 0;
        int maxi = 0, n = s.size(), l = 0, r = l;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') ca++;
            else if(s[i] == 'b') cb++;
            else if(s[i] == 'c') cc++;            
        }

        if(!(ca >= k && cb >= k && cc >= k)) return -1;

        while(l < n && r < n) {
            while(r < n &&(ca >= k && cb >= k && cc >= k)) {
                if(s[r] == 'a') ca--;
                else if(s[r] == 'b') cb--;
                else if(s[r] == 'c') cc--;  
                if((ca >= k && cb >= k && cc >= k)) maxi = max(maxi, r - l + 1);
                r++;
            }            
            if(s[l] == 'a') ca++;
            else if(s[l] == 'b') cb++;
            else if(s[l] == 'c') cc++;    
            l++;     
        }

        return n - maxi;
    }
};