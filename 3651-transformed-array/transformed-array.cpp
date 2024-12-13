class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size(), j;
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++) {
            j = (i + nums[i])%n;
            if(j < 0) j += n;
            ans[i] = nums[j];
        }
        return ans;
    }
};