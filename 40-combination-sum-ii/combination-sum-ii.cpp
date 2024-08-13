class Solution {
public:

    void solve(int i, vector<int>& candidates, int &target, vector<vector<int>> &ans, vector<int> &nums, int &sum) {

        if(i >= candidates.size()) {    

            if(sum == target) {
                sort(nums.begin(), nums.end());
                ans.push_back(nums);
            }        
            return;
        }       
        if(sum > target) return;

        // inc
        nums.push_back(candidates[i]);
        sum += candidates[i];
        solve(i+1, candidates, target, ans, nums, sum);
        nums.pop_back();
        sum -= candidates[i];

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1] ) {
            i++;
        }

        // exc
        solve(i+1, candidates, target, ans, nums, sum);      


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        int sum = 0;

        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ans, nums, sum);
        // sort(ans.begin(), ans.end());

        return ans;
    }
};