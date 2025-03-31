using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
       ll n = weights.size(), min = 0, max = 0;
       vector<ll> nums(n-1);
       if(n == 1) return 0;
       for(int i = 0; i < n - 1; i++) {
         nums[i] = weights[i] + weights[i+1];
       }
       sort(nums.begin(), nums.end());
        for(int i = 0; i < k - 1 ; i++) min += nums[i];
        for(int i = 0 ; i < k - 1; i++) max += nums[n - 2 - i];
        return max - min;
    }
};