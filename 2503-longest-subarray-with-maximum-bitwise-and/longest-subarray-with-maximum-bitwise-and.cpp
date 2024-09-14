class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ans = 0, maxi = 0, ans = 0;

        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i] >= maxi) {                
                ans = 1;
                if(i >= nums.size()) break;
                while(i < nums.size() - 1 && nums[i] == nums[i+1]) {
                    ans++;
                    i++;                    
                }
                if(nums[i] == maxi) max_ans = max(max_ans, ans);
                else max_ans = ans;
                maxi = nums[i];
            }
            
        }
        return max_ans;
        
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();