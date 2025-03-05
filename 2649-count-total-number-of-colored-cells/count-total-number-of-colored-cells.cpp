using ll = long long int;
class Solution {
public:
    long long coloredCells(int n) {
        ll ans = 1;
        for(int i = 1 ; i < n; i++) {
            ans += i*4;
        }
        return ans;
    }
};