using ll = long long;
class Solution {
public:
    int countDays(int n, vector<vector<int>>& nums) {
        int ans = 0, j, maxi;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            j = i;
            maxi = nums[i][1];
            while(j < nums.size() && maxi >= nums[j][0]) {
                maxi = max(maxi, nums[j][1]);
                j++;
                if(j >= nums.size()) break;
            } 
            ans += (maxi - nums[i][0]) + 1;
            i = j - 1;
        }
        
        return n - ans;
    }
};