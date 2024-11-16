class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n, prod = 1;

        for(int i = 0 ; i < 10; i++) {
            temp = n + i, prod = 1;
            while(temp) {
                prod *= temp%10;
                temp /= 10;                
            }
            if(prod%t == 0) return n + i;
        }
        return -1;
    }
};