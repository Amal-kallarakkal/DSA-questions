#pragma GCC optimize("OFast")
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios::sync_with_stdio(0);
        int cnt = 0;
        int n = heights.size();
        vector<int> nums(n);
        for(int i = 0 ; i < heights.size(); i++) {
            nums[i] = heights[i];
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n ; i++) {
            if( nums[i] != heights[i]) cnt++;
        }

        return cnt;
    }
};