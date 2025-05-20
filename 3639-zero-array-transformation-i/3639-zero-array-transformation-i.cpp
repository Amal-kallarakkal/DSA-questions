class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> nums2(n+1);

        for(int i = 0 ; i < queries.size(); i++) {
            nums2[queries[i][0]]++;
            nums2[queries[i][1] + 1]--;
        }
        for(int i = 1 ; i < n ; i++) {
            nums2[i] += nums2[i - 1];
        }

        for(int i = 0 ; i < n; i++) {
            if(nums[i] > nums2[i]) return false;
        }

        return true;
    }
};