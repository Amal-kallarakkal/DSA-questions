class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        while(n) {
            // if(n == 1 || n == -1) return true;
            if((n%2 && n > 2) || n <= 0) return false;
            n = n/2;
        }
        return true;
    }
};