class Solution {
public:
    int findChampion(int n, vector<vector<int>>& nums) {
        int ans = -1;
        vector<vector<int>> parent(n + 1);

        for(int i = 0; i < nums.size() ; i++) {
            parent[nums[i][1]].push_back(nums[i][0]);
        }
        for(int i = 0 ; i < n ; i++) {
            if(parent[i].size() == 0) {
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};