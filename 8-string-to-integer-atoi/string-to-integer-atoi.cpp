using ll = long long;

class Solution {
public:
    
    pair<string, bool> Clean(string s) {
        bool neg = false;
        string ans = "";
        bool pos = false;
        bool  zero = false;
        for(int i = 0 ; i < s.size(); i++) {
            if(!ans.size() && s[i] == '0') {
                zero = true;
                continue;
            } 
            if(!ans.size() && ((!zero && !pos) && s[i] == '+')) {
                pos = true;
                if(!ans.size())continue;
            }
            if(!ans.size() && ((!zero && !neg) && s[i] == '-'))  {
                neg = true;
                if(!ans.size()) continue;
            }
            if(pos && neg) break;
            if(int(s[i]) >= 48 && int(s[i]) <= 57 ) {
                ans += s[i];
            } else if(s[i] != ' ' || (((zero || pos|| neg)|| ans.size() != 0) && s[i] == ' ')) break;
        }

        pair<string, bool> x = make_pair(ans, neg);

        return x;
    }

    int myAtoi(string s) {
        ll ans = 0;
        pair<string, bool> x = Clean(s);

        s = x.first;
        bool neg = x.second;
        int n = s.size();
        if(n > 10) {
            if(neg)return INT_MIN;
            return INT_MAX;
        };
        if(n == 0) return 0;
        int  i = 0;
        while(i < s.size()) {
            (neg)?ans -= pow(10,n-1-i)*(s[i] - '0'):ans += pow(10,n-1-i)*(s[i] - '0');
            i++;
        }
        
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;
        // if(neg) {
        //     if(ans == INT_MAX) ans = -ans -1;
        //     else ans = -ans;
        // }
        return ans;
    }
};