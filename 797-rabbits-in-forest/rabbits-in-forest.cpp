class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0 ; i < n; i++) mp[nums[i]]++;

        for(auto i : mp) ans += (i.first + 1)*(ceil(i.second*1.0/(i.first + 1)));

        return ans;
    }
};