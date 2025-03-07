class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size(), l, h, mid, ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n; i++) {
            l = i;
            h = n-1;
            while(l <= h) {
                mid = (l + h)/2;
                if(2*k >= nums[mid] - nums[i]) {
                    l = mid + 1;
                } else h = mid - 1;
            }
            ans = max(ans, h - i + 1);
            if(h == n-1) return ans;
        }
        return ans;
    }
};