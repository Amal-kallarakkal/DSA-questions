class Solution {
public:

    int minBitFlips(int start, int goal) {
        int cnt = 0;
        string s = "";
        string g = "";   
        
         while(start || goal) {
            if(start%2) {
                s += '1';
            } else {
                s += '0';
            }
            start /= 2;

            if(goal%2) {
                g += '1';
            } else {
                g += '0';
            }
            goal /= 2;
        }

        int is = 0, ig = 0;
        
        while(is < s.size() && ig < g.size()) {
            if(s[is++] != g[ig++]) cnt++;
        }

        

        return cnt;

    }
};