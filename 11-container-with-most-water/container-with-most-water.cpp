class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size(), ans = 0, l = 0, r = n - 1, area = 0, mini;
        
        while(l < n && l < r) {
            mini = min(nums[l], nums[r]);
            area = mini*(r - l);
            ans = max(ans, area);
            if(nums[l] < nums[r]) l++;
            else r--;
        }
        return ans;
    }
};