class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);  
        if(sum % k == 0) return true;
        else if(nums.size() == 2) return false;

        set<int> st;
        int curr_sum = 0;
        int prev_sum = nums[0]%k;
        nums[0] %= k;

        for(int i = 1 ; i < nums.size() ; i++) {
            
            nums[i] = nums[i-1] + nums[i];
            nums[i] %= k;          
            if(st.count(nums[i]) || !nums[i] ) return true;
            st.insert(nums[i-1]);
            
        }        
        
        return false;
    }
}; 