using ll = long long int;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll n = nums.size(), fsum = 0, bsum = 0, ans = 0;
        vector<ll> fw(n), bw(n);
        for(int i = 0 ; i < n; i++) {
            fsum += nums[i];
            bsum += nums[n-i-1];
            fw[i] = fsum;
            bw[n - i - 1] = bsum;
        }
        for(int i = 0; i < n - 1; i++) {
            if(fw[i] >= bw[i+1]) ans++;
        }
        return ans;
    }
};