class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] < k) return -1;
        unordered_set<int> set;
        for(int x : nums) set.insert(x);
        
        return (set.count(k)) ? set.size() - 1 : set.size();

    }
};