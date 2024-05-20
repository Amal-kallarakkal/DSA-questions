class Solution {
public:

    int solve(vector<int>& nums,  int i, int Xor) {

        if(i >= nums.size()) return Xor;

        // excluding         
        int exc = solve(nums, i + 1, Xor);
       
        // including        
        Xor = Xor xor nums[i];        
        int inc = solve(nums, i + 1, Xor);
        
        return inc + exc;
    }
    int subsetXORSum(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int i = 0;
        int Xor = 0;
        int Xor_sum = solve(nums,i, Xor);
      
        return Xor_sum;
    }
};