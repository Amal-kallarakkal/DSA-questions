#pragma GCC optimize("OFast")
class Solution {
public:
    // ios::sync_with_stdio(0);
    int numWaterBottles(int numBottles, int numExchange) {
        
        return (numBottles*numExchange-1)/(numExchange-1);
    }
};