class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int ans = 0;
        int mini = INT_MAX;
        for(int x : nums) {
            mini = min(mini, x);
        }

        for(int x : nums) {
            if(x%mini) return 1;
            if(x == mini) ans++;
        }

        return ceil(double(ans)/2);
    }
};