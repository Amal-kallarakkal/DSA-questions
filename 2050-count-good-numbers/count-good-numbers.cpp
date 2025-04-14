class Solution {
public:
    int m = 1000000007;
    int Pow(long long x, long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n%2) return (x * Pow(((x)%m * (x)%m)%m, n/2))%m;
        return Pow(((x)%m * (x)%m)%m, n/2)%m;
    }
    int countGoodNumbers(long long n) {                
        return (1LL * Pow(5,n - n/2) % m * Pow(4, n/2) % m) % m;

    }
};