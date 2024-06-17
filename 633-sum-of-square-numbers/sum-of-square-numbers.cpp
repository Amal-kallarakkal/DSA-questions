using ll = long long;
class Solution {
public:
    bool judgeSquareSum(int c) {
        
        ll low = 0 , high = sqrt(c);   
        ll sum = 0;
       
        while(low <= high) {
            sum = low*low + high*high;
            if(sum > c) high--;
            else if(sum == c) return true;
            else low++;   
           
        }           
        

        return false;
    }
};