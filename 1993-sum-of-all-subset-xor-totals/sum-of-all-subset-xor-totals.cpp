class Solution {
public:

    int solve(vector<int>& nums,  int i, int Xor) {
        if(i >= nums.size()) return Xor;
        return solve(nums, i + 1, Xor xor nums[i]) + solve(nums, i + 1, Xor);
    }
    int subsetXORSum(vector<int>& nums) {
        ios::sync_with_stdio(0);    
        return solve(nums, 0, 0);;
    }
};