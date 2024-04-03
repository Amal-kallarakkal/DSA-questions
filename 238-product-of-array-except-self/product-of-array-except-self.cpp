class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int curr = 1;
       int n = nums.size();
       vector<int> output(n,1);
       for(int i = 1; i < n ; i++) {
        curr *= nums[i-1];
        output[i] = curr;
       }
       curr = 1;

       for(int i = n-2; i >= 0 ; i--) {
        curr *= nums[i+1];
        output[i] *= curr;         
       }


       return output;
    }
};