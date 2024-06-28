#pragma GCC optimize("OFast")
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        double ans = 0;
        double sum = 0;
        int j = 0;
        double maxi = 0;

        for(int i = 0; i < k; i++) sum += nums[i];

        maxi = sum/k;
        
        for(int i = 0  ; i < nums.size() - k   ; i++) {
            j = i + k;
            
            sum -= nums[i];            
            sum += nums[j];
            ans = sum/k;
            
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};