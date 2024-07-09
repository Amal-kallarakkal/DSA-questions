#pragma GCC optimize("OFast")
class Solution {
public:
    // ios::sync_with_stdio(0);
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> wait(n, 0);
        int time = 0;
        
        for(int i = 0; i < n ; i++) {
            
            if(time <= nums[i][0] ){
                time += nums[i][1] - (time - nums[i][0]);
            }  else {
                time += nums[i][1];
            }
            wait[i] = time - nums[i][0];
        }
        long long int sum = 0;
        return (accumulate(wait.begin(), wait.end(), sum))*1.0/n;
    }
};