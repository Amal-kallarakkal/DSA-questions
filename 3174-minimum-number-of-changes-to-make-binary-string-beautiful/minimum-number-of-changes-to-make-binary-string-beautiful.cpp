class Solution {
public:
    int minChanges(string s) {
        int i = 0, cnt = 0, j = 0, n = s.size(); 
        while(i < n) {
            j = i;
            while(j < n && s[i] == s[j] ) {
                j++;
            }
            if((j - i)%2) {
                cnt++;
                i = j +1;
            } else i = j;
        }
        return cnt;
    }
};