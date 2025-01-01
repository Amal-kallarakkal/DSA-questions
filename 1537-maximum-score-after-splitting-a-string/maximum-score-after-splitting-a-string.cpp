class Solution {
public:
    int maxScore(string s) {
        int ans = 0, zcnt = 0, ocnt = 0;
        vector<int> one(s.size(), 0), zero(s.size(), 0);
        for(int i = 0, j; i < s.size(); i++) {            
            if(s[i] == '0') {
                zcnt++;
                zero[i] = zcnt;
            } 
            j = s.size() - 1 - i;
            if(s[j] == '1') {
                ocnt++;
                one[j] = ocnt;
            }
        }
        for(int i = 0 ; i < s.size() - 1; i++) {
            ans = max(ans, one[i + 1] + zero[i]);
        }

        return ans;

    }
};