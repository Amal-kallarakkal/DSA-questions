class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int bin = 0;
        int i = 0;
        while(n) {
            bin += !(n%2)*pow(2,i);
            i++;
            n /= 2;
        }
        
        return bin;
    }
};