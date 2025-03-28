using ll = long long;
class Solution {
public:

    int binSrchLeft(int l, int h, vector<int>& nums, int &target, int &curr) {
        int n = nums.size(), sum, ans = -1, mid;
        while(l <= h && l < n && h >=0) {
            mid = (l + h)/2;
            sum = curr + nums[mid];
            if(sum >= target) {
                h = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }

    int binSrchRight(int l, int h, vector<int>& nums, int &target, int &curr) {
        int n = nums.size(), sum, ans = -1, mid;
        while(l <= h && l < n && h >=0) {
            mid = (l + h)/2;
            sum = curr + nums[mid];            
            if(sum <= target) {
                l = mid + 1;
                ans = mid;
            }
            else h = mid - 1;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ios::sync_with_stdio(0);
        ll cnt = 0;
        int n = nums.size(), sum, l, h, left, right, mid;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n - 1 ; i++) {
            l = i + 1;
            h = n-1;
            while(l <= h && l < n && h >=0) {
                mid = (l + h)/2;
                sum = nums[mid] + nums[i];
                if(sum >= lower && sum <= upper) break;
                else if(sum > upper) h = mid - 1;
                else l = mid + 1;
            }
            if(sum < lower || sum > upper) continue;
            left = binSrchLeft(i+1, mid, nums, lower, nums[i]);
            right = binSrchRight(mid, n-1, nums, upper, nums[i]);
            if(left < right) cnt += right - left + 1;
            else cnt++;

        }
        return cnt;

    }
};