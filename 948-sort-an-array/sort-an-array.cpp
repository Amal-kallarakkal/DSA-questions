class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<int> ans;
        int key , n;
        for(auto x : mp) {
            key = x.first;
            n = x.second;
            while(n--)  {
                ans.push_back(key);
            }
        }

        return ans;
    }
};