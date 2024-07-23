class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        

        for(int i = 0 ; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        map<int, vector<int>> mp2;
        for(auto x : mp) {
            mp2[x.second].push_back(x.first);
        }
        vector<int> ans;
        int k = 0;
        for(auto x: mp2) {
            sort(x.second.rbegin(), x.second.rend());
            for(int y : x.second)  {
                k = x.first;            
               while(k--) {
                ans.push_back(y);                
               }
            }
        }

        return ans;
    }
};