class Solution {
public:
    int mid;

    bool Possible(int &n, vector<int> &nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++) sum += ceil((nums[i]*1.0)/mid);
        if(sum <= n) return true;
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1, m = nums.size(), h = nums[m-1];
        while(l < h) {
            mid = (l + h)/2;
            if(Possible(n, nums)) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};