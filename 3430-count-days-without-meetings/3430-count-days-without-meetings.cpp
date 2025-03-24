using ll = long long;
class Solution {
public:
    int countDays(int n, vector<vector<int>>& nums) {
        int ans = 0, s, e, j, store;
        vector<vector<int>> nums2;
        sort(nums.begin(), nums.end());
        // for(int i = 0 ; i < nums.size(); i++) {
        //     cout<<"["<<nums[i][0]<<", "<<nums[i][1]<<"], ";
        // }cout<<endl;
        for(int i = 0; i < nums.size(); i++) {
            j = i;
            store = nums[i][1];
            while(j < nums.size() && store >= nums[j][0]) {
                store = max(store, nums[j][1]);
                j++;
                if(j >= nums.size()) break;
            } 
            ans += (store - nums[i][0]) + 1;
            // cout<<j<<", ans: "<<store<<", "<<nums[i][0]<<endl;
            i = j - 1;
        }
        
        return n - ans;
    }
};