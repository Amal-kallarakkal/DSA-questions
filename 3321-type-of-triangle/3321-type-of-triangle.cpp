class Solution {
public:
        string triangleType(vector<int>& nums) {
       
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        string ans = "";
        
        if((a < b+c) &&(( b < a+c) && (c < a + b))) {
                ans = "scalene";
         } else {
                ans = "none";
            
            return ans;
        }
            
        
        if((a == b) && (b == c) ) ans = "equilateral";
        else if((a == b) || (b == c) || (a == c) ) ans = "isosceles";
        
        
        
        return ans;
    }

};