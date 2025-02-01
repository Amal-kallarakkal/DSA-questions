class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int oddcnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i]%2;
        }

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) return false;
        }
        return true;
    }
};