class Solution {
public:

    bool solve(int &mid, vector<int>& nums, int &p) {
        int cnt = 0, i = 0, n = nums.size();

        while(i < n - 1) {
            if(nums[i + 1] - nums[i] <= mid) {
                cnt++;
                i += 2;
            } else i++;
            if(cnt >= p) return true;
        }
        return false;
        
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, l = 0, h = nums[n-1], mid;
        // for(int i = 0 ; i < n; i++) cout<<nums[i]<<" ";
        while(l <= h) {
            mid = l + (h - l)/2;
            // cout<<endl<<"mid: " <<mid;

            if(solve(mid, nums, p)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid +1;
            }
        }
        
      return ans;
    }
};