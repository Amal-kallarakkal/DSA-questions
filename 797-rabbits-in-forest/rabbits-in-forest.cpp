class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n; i++) {
            if(nums[i]) mp[nums[i]]++;
            else ans++;
        }
        for(auto i : mp) {
            if(i.first + 1 < i.second) ans += (i.first + 1)*(ceil(i.second*1.0/(i.first + 1)));
            else ans += i.first + 1;
            // cout<<"ans after "<<i.first<<" -> "<<i.second<<" : "<<ans<<endl;
        }
        return ans;
    }
};