class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int i = 0, j = 0, sum = 0, n = nums.size();

        while(i < n) {
            while(j < n && sum < target) {
                sum += nums[j];
                j++;
            }
            if(sum >= target) mini = min(mini, j - i);
            sum -= nums[i];
            i++;
        }

        if(mini == INT_MAX) return 0;
        return mini;        
    }
};