#pragma GCC optimize("OFast")
using ll = long long;
class Solution {
public:
    bool isHappy(int n) {
        ios::sync_with_stdio(0);
        unordered_set<int> st;
        int sum = 0;
        int rem = 0;
        while(!st.count(n)) {
            st.insert(n);
            while(n) {
                rem = n%10;
                sum += rem*rem;
                n /= 10;
            }
            if(sum == 1) return true;
            
            n = sum;
            sum = 0;
        }
        return false;
    }
};