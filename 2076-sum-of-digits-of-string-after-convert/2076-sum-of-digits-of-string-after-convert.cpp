using ll = long long;
class Solution {
public:
    int getLucky(string s, int k) {
        ll ans = 0;
        ll temp ;
        string nums;

        for(int i = 0 ; i < s.size(); i++) {
            temp = int(s[i]) - 96;  
            while(temp) {
                ans += temp%10;
                temp /= 10;
            }          
        }
        temp = ans;
        k--;
        while(k--) {
            temp = ans;
            ans = 0;
            while(temp) {
                ans += temp%10;
                temp /= 10;
            }
        }
        return ans;
    }
};