#pragma GCC optimize("OFast")
class Solution {
public:
    int countPrimes(int n) {
        ios::sync_with_stdio(0);
        vector<bool> prime(n+1,true);
        int count = 0;

        prime[0] = prime[1] = 0;
        for(int i=0;i<n;i++){

            if(prime[i]){
                count++;
                for(int j = 2*i ; j<n ; j = j+i){
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};