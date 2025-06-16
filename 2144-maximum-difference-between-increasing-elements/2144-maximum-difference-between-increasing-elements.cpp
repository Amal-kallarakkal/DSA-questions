class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        vector<int> nextMax = nums, maxans(n); 
        
        for(int i = n - 2; i >= 0; i--) {
            nextMax[i] = max(nextMax[i+1], nextMax[i]);
        }
        for(int i = 0 ; i < n - 1; i++) {
            maxans[i] = nextMax[i+1] - nums[i];
        }
        for(int i = 0; i < n - 1; i++) ans = max(ans, maxans[i]);
        return (ans > 0) ? ans: -1 ;
    }
};