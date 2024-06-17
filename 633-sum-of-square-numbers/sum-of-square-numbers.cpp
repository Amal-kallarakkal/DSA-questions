using ll = long long;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int root = sqrt(c);
        ll low = 0 , high = root;
        // bool ans = false;
        ll sum = 0;
       
        while(low <= root && low <= high) {
            sum = low*low + high*high;
            if(sum > c) high--;
            else if(sum == c) return true;
            else low++;   
            // cout<<sum<<endl;            
        }           
        

        return false;
    }
};