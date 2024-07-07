#pragma GCC optimize("OFast")
class Solution {
public:
    // ios::sync_with_stdio(0);
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, sum = 0 ;
        
        while(numBottles) {
            sum += numBottles;
            empty += numBottles;
            numBottles = empty/numExchange;
            empty = empty%numExchange;            
        }
        return sum;
    }
};