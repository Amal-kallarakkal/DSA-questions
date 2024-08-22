class Solution {
public:
    int findComplement(int num) {
        int bin = 0;
        int i = 0;
        while(num) {
            bin += !(num%2)*pow(2,i);
            i++;
            num /= 2;
        }
        
        return bin;
    }
};