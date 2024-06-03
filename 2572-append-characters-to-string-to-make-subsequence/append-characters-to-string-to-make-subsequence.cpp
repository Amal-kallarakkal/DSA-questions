class Solution {
public:
    int appendCharacters(string s, string t) {

        int ti = 0;
        int maxi = 0;
        int cnt= 0;
        for(int i = 0 ; i < s.size(); i++) {
            
            while(ti < t.size() && s[i] == t[ti]) {
                cnt++;
                ti++;
                i++;
            }
            
        }

        return t.size() - cnt;
        
    }
};