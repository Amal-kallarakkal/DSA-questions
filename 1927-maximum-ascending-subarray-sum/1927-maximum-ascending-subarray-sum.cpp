class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++)  {

            if(i == nums.size() - 1) {
                sum += nums[i];
                ans = max(sum, ans);
            } else if(nums[i] >= nums[i+1]) {
                sum += nums[i];
                ans = max(sum, ans);
                sum = 0;
            } 
            else {
                sum += nums[i];
            }
        }
        return ans;
    }
};