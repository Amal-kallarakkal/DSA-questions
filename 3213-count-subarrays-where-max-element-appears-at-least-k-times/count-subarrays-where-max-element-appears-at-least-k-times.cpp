using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans = 0, x = 0, xcnt = 0;

        for(int i = 0 ; i < nums.size(); i++) x = max(x, ll(nums[i]));

        int l = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i] == x) xcnt++;
            while(l <= i && xcnt >= k) {
                ans += nums.size() - i;
                if(nums[l] == x) xcnt--;
                l++;
            }
        };

        
        return ans;
        
    }
};