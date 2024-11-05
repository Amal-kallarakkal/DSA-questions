class Solution {
public:
    int minChanges(string s) {
        int i = 0, cnt = 0, j = 0, n = s.size(); 
        // reverse(s.begin(), s.end());
        // cout<<s<<endl;
        while(i < n) {
            j = i;
            while(j < n && s[i] == s[j] ) {
                j++;
            }
            if(j > n) break;
            if((j - i)%2) {
                // cout<<j<<" - "<<i<<endl;
                if(s[j] == '1') s[j] = '0';
                else s[j] = '1';
                cnt++;
                i = j +1;
            } else i = j;
            // cout<<i<<endl;
        }
        // cout<<s;
        // cout<<endl<<n;
        return cnt;
    }
};