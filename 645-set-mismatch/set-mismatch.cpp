class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans ;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int miss = 0;
        int val = 1;
        map<int,int> mp;

        for(int i = 0 ; i < n  ; i++) {

            mp[nums[i]]++;
        }

        for(int i = 1 ; i <= n ; i++) {
            if(mp.find(i) == mp.end()) {
                miss =  i;
            }
            if(mp[i] == 2) {
                ans.push_back(i);
                if(miss) break;
            } 
        }

        ans.push_back(miss);
        return ans;
        
    }
};