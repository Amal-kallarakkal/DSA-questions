class Solution {
public:
    bool canBeValid(string s, string locked) {
        int opencnt = 0, closecnt = 0, wildcnt = 0, n = s.size();
        if(n&1) return false;
        for(int i = 0; i < n; i++) {
            if(locked[i] == '1') {
                if(s[i] == ')') closecnt++;
                else opencnt++;
            } else wildcnt++;
            if(closecnt > opencnt + wildcnt) return false;
        }
        opencnt = 0, closecnt = 0, wildcnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(locked[i] == '1') {
                if(s[i] == ')') closecnt++;
                else opencnt++;
            } else wildcnt++;
            if(opencnt > closecnt + wildcnt) return false;
        }
        return true;
    }
};