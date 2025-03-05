using ll = long long int;
class Solution {
public:
    long long coloredCells(int n) {
        ll ans = 1;
        ll m = n;
        ans = 2*m*m - 2*m + 1;
        return ans;
    }
};