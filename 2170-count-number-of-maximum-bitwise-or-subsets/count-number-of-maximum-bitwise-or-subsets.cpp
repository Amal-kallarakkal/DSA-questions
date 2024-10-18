class Solution {
public:
    void solve(int i, vector<int>& nums, map<int, int> &mp, int mxor) {
        if(i >= nums.size()) {
            return;
        }
        // inc
        mp[mxor|nums[i]]++;
        solve(i+1, nums, mp, mxor|nums[i]);
        // exc
        solve(i+1, nums, mp, mxor);

    }
    int countMaxOrSubsets(vector<int>& nums) {        
        map<int, int> mp;
        solve(0, nums, mp, 0);
        auto last = prev(mp.end());        
        return last->second;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;    
}();
