class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0, a, b, c;
        sort(nums.rbegin(), nums.rend());

        for(int i = 0; i < nums.size() - 2; i++) {
            a = nums[i], b = nums[i+1], c = nums[i+2];
            if(a < b + c && b < a + c && c < a + b) {
                // cout<<a + b + c<<endl;
                ans = max(a + b + c, ans);
            }
        }
        return ans;
    }
};