class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // unordered_set<int> set;
        sort(nums.begin(), nums.end());
        int diff = 0;
        int ans = 0;
        for(int i = 0 ; i  < nums.size() - 1; i++) {
            if(nums[i ] >= nums[i+1] ) {
                diff = nums[i] - nums[i+1] + 1;
                nums[i+1] += diff;
                ans += diff;
            }
        }

        for(int i = 0 ; i  < nums.size(); i++) cout<<nums[i]<<" ";

        return ans;
    }
};