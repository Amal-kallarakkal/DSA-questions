using ll = long long;

ll m = pow(10, 9) + 7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int sum = 0;
        for(int i = 0 ; i < nums.size() - 1; i++) {
            sum = nums[i];
            ans.push_back(sum);
            for(int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                ans.push_back(sum);
            }
        }

        ans.push_back(nums[nums.size() - 1]);
        sort(ans.begin(), ans.end());
        sum = 0;

        for(int i = left - 1; i < right; i++) {
            sum = (sum%m +  ans[i]%m)%m;
        }

        return sum;
    }
};