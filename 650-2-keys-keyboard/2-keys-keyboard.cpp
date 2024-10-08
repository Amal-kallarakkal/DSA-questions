class Solution {
public:
    int minSteps(int n) {        
        int ans = 0;
        int i = 2;
        while(i < n) {
            while(n%i == 0) {
                n /= i;
                ans += i;
            }
            i++;
        }
        
        if(n != 1) ans += n;

        return ans;

    }
};