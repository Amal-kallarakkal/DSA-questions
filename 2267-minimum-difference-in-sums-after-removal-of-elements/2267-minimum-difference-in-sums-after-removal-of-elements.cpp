using ll = long long;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N / 3;

        // Track minimum sum after removing n largest from first 2n elements
        priority_queue<int> maxhp;
        ll leftSum = 0;
        vector<ll> mini(n + 1);

        for (int i = 0; i < 2 * n; ++i) {
            leftSum += nums[i];
            maxhp.push(nums[i]);

            if (maxhp.size() > n) {
                leftSum -= maxhp.top();
                maxhp.pop();
            }

            if (i >= n - 1) mini[i - (n - 1)] = leftSum;
        }

        // Track maximum sum after removing n smallest from last 2n elements
        priority_queue<int, vector<int>, greater<int>> minhp;
        ll rightSum = 0;
        vector<ll> maxi(n + 1);

        for (int i = N - 1; i >= n; --i) {
            rightSum += nums[i];
            minhp.push(nums[i]);

            if (minhp.size() > n) {
                rightSum -= minhp.top();
                minhp.pop();
            }

            if (i <= 2 * n) maxi[(2 * n) - i] = rightSum;
        }

        // Compute minimum difference
        ll ans = LLONG_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, mini[i] - maxi[n - i]);
        }

        return ans;
    }
};
