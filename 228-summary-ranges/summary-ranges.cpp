class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        string ans;
        if(nums.size() == 1) {
            s.push_back(to_string(nums[0]));
            return s;
        }
        int j, n = nums.size();
        for(int i = 0 ; i < nums.size(); i++) {
            ans = to_string(nums[i]);
            j = i;
            while(j < n - 1 && (nums[j] + 1 == nums[j + 1])) {
                j++;
            }
            if(i != j) ans += "->" + to_string(nums[j]);
            s.push_back(ans);
            i = j;
        }
        return s;
    }
};