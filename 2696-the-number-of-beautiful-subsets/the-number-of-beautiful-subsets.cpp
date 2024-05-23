using ll = long long int;
class Solution {
public:

    void solve(int i , int &ans, unordered_map<int,int> &output, vector<int> &nums, int k){
        
        
        if(i >= nums.size()) {
            ans++;
            return;
        }
        // .exclude
        solve(i + 1, ans, output, nums, k);

        // inclusion with a check
        if(!output[nums[i] - k] && !output[nums[i] + k]) {
            output[nums[i]]++;
            solve(i + 1, ans, output, nums, k);
            output[nums[i]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        // ios::sync_with_stdio(0);

        int n = nums.size();
        // sort(nums.begin(), nums.end());

        unordered_map<int, int> output;
        int ans;
        solve(0, ans, output, nums, k);       
        output.clear();

        return ans - 1;
    }
};