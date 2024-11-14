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
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(), nums.end());
        return BinSrch(1, nums[nums.size() - 1], nums, n);
    }
};