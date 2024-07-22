#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int , string> mp;
        vector<pair<int, string>> nums;
        int n = names.size();
        for(int i = 0; i < n; i++) {
            nums.push_back({heights[i],names[i]});
        }
        vector<string> ans(n);
        sort(nums.rbegin(), nums.rend());
        for(int i = 0 ; i < n; i++) {
            ans[i] = nums[i].second;
        }
        return ans;
    }
};