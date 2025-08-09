class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n) {
            if(n%2 && n > 2) return false;
            n = n/2;
        }
        return true;
    }
};