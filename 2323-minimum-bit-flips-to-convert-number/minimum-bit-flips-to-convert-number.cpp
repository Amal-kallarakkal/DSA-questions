class Solution {
public:
    string binary(int n) {
        string ans = "";
        while(n) {
            if(n%2) {
                ans += '1';
            } else {
                ans += '0';
            }
            n /= 2;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        string s = binary(start);
        string g = binary(goal);   
        

        int is = 0, ig = 0;
        if(s.size() > g.size()) {
            int i = 0 ; 
            int diff = s.size() - g.size();
            while(i < diff) {
                g += '0';
                i++;
            }
        } else if(g.size() > s.size()) {
            int i = 0 ; 
            int diff = g.size() - s.size();
            while(i < diff) {
                s += '0';
                i++;
            }
        }

        while(is < s.size() && ig < g.size()) {
            if(s[is++] != g[ig++]) cnt++;
        }

        

        return cnt;

    }
};