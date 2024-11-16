
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 1) return nums;
        int i = 0, j = i;
        while(i < nums.size() - k + 1) {
            bool isContiguous = true;
            j = i;
            while(j < i + k - 1) {
                if(nums[j] + 1 != nums[j+1]) {
                    ans.push_back(-1);
                    isContiguous = false;
                    break;
                } 
                j++;
            }
            if(isContiguous) {
                ans.push_back(nums[j]);
            }
            i++;
        }
       
        return ans;
    }
};
