class Solution {
public:
    bool prime(int n) {
        for(int i = 2; i <= sqrt(n); i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> nums;
        vector<int> ans = {-1, -1};
        int diff = INT_MAX;
        for(int i = left; i <= right; i++) {
            if(i <= 1) continue;
            if(prime(i)) {
                nums.push_back(i);
            }
        }
        if(nums.size() == 0) return ans;
        for(int i = 0 ; i < nums.size() - 1; i++) {
            if(diff > nums[i+1] - nums[i]) {
                // cout<<nums[i];
                diff = nums[i+1] - nums[i];
                ans[0] = nums[i];
                ans[1] = nums[i+1];
            }
        }
        return ans;       
    }
};