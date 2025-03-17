using ll = long long;
class Solution {
public:
    bool possible(ll mid, vector<int> &nums, int k) {
        ll j;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > mid) return false;
            j = sqrt(mid / (double)nums[i]);
            k -= j;
            if(k <= 0) return true;            
        }
        return false;
    }
    long long repairCars(vector<int>& nums, int cars) {
        ll l, h, mid, n = nums.size(), min = pow(ceil((cars*1.0)/n), 2);
        sort(nums.begin(), nums.end());
        l = 1;
        h = min*nums[n-1];
        while(l < h) {
            mid = (h + l)/2;
            if(possible(mid, nums, cars)) {
                h = mid;
            } else l = mid + 1;
        }
        return h;
    }
};