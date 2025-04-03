using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0, maxi = 0, maxDiff = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, maxDiff*ll(nums[i]));
            maxi = max(maxi, ll(nums[i]));
            maxDiff = max(maxDiff, maxi - ll(nums[i]));
        }
        return ans;
    }
};