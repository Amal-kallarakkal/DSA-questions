class Solution {
public:
    int Setcnt(int n) {
        int cnt = 0;
        while(n) {
            if(n&1) cnt++;
            n = n>>1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        int cnt1 = Setcnt(num1), cnt2 = Setcnt(num2);
        long long int x = num1, diff = cnt2 - cnt1, i = abs(diff);
        if(diff) {
            if(diff > 0) {
                // set rightmost bits
                while(i) {
                    x = x|(x+1);
                    i--;
                }
            } else {
                // unset rightmost bits
                while(i) {
                    x = x&(x-1);
                    i--;
                }
            }
        }
        return x;
    }
};