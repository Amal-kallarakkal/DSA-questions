class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int start = 0;
        int end = start;
        int maxi = INT_MIN;
        int ans = 1;

        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i-1] < nums[i]) {
                end = i;
            } else {
                start = i;
                end = start;
            }
            maxi = end - start + 1;
            ans = max(ans, maxi);
        }
        start =  nums.size() - 1;
        end = start;
        for(int i = nums.size() - 2 ; i >=0 ; i--) {
            if(nums[i + 1] < nums[i]) {
                end = i;
            } else {
                start = i;
                end = start;
            }
            maxi = abs(end - start) + 1;
            ans = max(ans, maxi);
        }

        return ans;
    }
};