class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int carry = 0, sum = 0 ;
        int empty = 0;
        while(numBottles) {
            sum += numBottles;
            empty += numBottles;
            // cout<<empty<<endl;
            // carry = numBottles%numExchange;
            numBottles = empty/numExchange;
            empty = empty%numExchange;
            
        }
        return sum;
    }
};