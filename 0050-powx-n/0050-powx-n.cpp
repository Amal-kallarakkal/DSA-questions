class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0){
            x = 1.0/x;
            if(n == INT_MIN){
                x *= x;
                n = INT_MAX;
            }
            else n = abs(n);
        }
        if(n%2) return x * myPow(x*x, n/2);
        return myPow(x*x, n/2);
    }
};