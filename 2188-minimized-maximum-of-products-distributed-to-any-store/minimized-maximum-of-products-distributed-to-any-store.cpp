class Solution {
public:
    bool Possible(int &n, vector<int> &nums, int &mid) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++) sum += ceil((nums[i]*1.0)/mid);
        if(sum <= n) return true;
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& nums) {
        int l = 1, h = 0, mid;
        for(int &i : nums) h = max(h, i);
        while(l < h) {
            mid = (l + h)/2;
            if(Possible(n, nums, mid)) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};