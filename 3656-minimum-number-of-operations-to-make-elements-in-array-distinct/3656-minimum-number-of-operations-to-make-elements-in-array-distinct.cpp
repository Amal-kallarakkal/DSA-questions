class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), j = 0, maxi = -1;
        unordered_map<int, int> mp;
        vector<int> num2(n);
        for(int i = n - 1 ; i >= 0; i--) {
            mp[nums[i]]++;
            num2[i] = mp[nums[i]];
        }
        for(int i = 0 ; i < n; i++) {
            if(num2[i] > 1) maxi = i;
        }

        return (maxi > -1) ? ceil((maxi + 1)*1.0/3) : 0;
    }
};