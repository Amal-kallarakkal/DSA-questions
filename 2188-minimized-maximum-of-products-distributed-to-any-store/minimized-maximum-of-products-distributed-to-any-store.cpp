class Solution {
public:
    int mid;

    bool Possible(int &mid,int &n, vector<int> &nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            sum += ceil((nums[i]*1.0)/mid);
        }
        if(sum <= n) return true;
        return false;
    }
    int BinSrch(int l, int h, vector<int> &nums, int &n) {
        if(l >= h) return h;

        mid = (l + h)/2;

        if(Possible(mid, n, nums)) return BinSrch(l, mid, nums, n);
        else return BinSrch(mid + 1, h, nums, n);

        return -1;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        // if(n == m) return nums[m - 1];

        return BinSrch(1, nums[m-1], nums, n);
    }
};