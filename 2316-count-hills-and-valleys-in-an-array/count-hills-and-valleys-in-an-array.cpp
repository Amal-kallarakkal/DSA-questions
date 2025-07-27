class Solution {
public:
    int countHillValley(vector<int>& nums2) {
        int cnt = 0, n = nums2.size();
        vector<int> nums;
        nums.push_back(nums2[0]);

        for(int i = 1 ; i < n ; i++) {
            if(nums2[i] != nums2[i-1]) nums.push_back(nums2[i]);
        }

        // for(int i: nums) cout<<i<<" ";

        for(int i = 1;  i < nums.size() - 1; i++) {
            // valley
            if(nums[i - 1] >= nums[i] && nums[i] < nums[i+1]) cnt++;
            // hill
            else if(nums[i-1] < nums[i] && nums[i] >= nums[i+1]) cnt++;
        }
        // for(int i = 1; i < n - 1 ; i++) {
            // // valley
            // if(nums[i - 1] >= nums[i] && nums[i] < nums[i+1]) cnt++;
            // // hill
            // else if(nums[i-1] < nums[i] && nums[i] >= nums[i+1]) cnt++;
        // }
        return cnt;
    }
};