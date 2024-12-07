class Solution {
public:
    bool possible(int &mid, vector<int> &nums, int &max) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            sum += ceil(nums[i]*1.0/mid) - 1;
            if(sum > max) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int low = 1, high, mid, ans;  
        sort(nums.rbegin(), nums.rend())      ;
        high = nums[0];
        while(low <= high) {
            mid = (high - low)/2 + low;
            if(possible(mid, nums, maxOperations)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};