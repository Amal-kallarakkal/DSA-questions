class Solution {
public:
    int passThePillow(int n, int time) {
        
        int mod = time% (n - 1);
        int turn = time/(n - 1);
        if(turn%2) {
            return n - mod;
        } else return mod + 1;
        return 1;
    }
};