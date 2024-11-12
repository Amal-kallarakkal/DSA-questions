class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& nums, vector<int>& queries) {
        int n = queries.size(), maxi = 0, m = nums.size(), l, h, mid;
        vector<int> ans(n);

        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < m; i++) {
            maxi = max(nums[i][1], maxi);
            nums[i][1] = maxi;
        }

        for(int i = 0 ; i < n; i++) {
            l = 0, h = m - 1;
            while(l <= h) {
                mid = (l + h)/2;
                if(nums[mid][0] > queries[i]) h = mid - 1;
                else {
                    ans[i] = max(ans[i], nums[mid][1]);
                    l = mid + 1;
                }
            }
                
        }
        return ans;
    }
};