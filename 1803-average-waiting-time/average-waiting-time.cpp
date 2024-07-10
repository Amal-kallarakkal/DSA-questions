#pragma GCC optimize("OFast")
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n = nums.size();
        long long int sum = 0;        
        int time = 0;
        
        for(int i = 0; i < n ; i++) {
            
            if(time <= nums[i][0] ){
                time += nums[i][1] - (time - nums[i][0]);
            }  else {
                time += nums[i][1];
            }
            sum += time - nums[i][0];
        }
        return (sum)*1.0/n;
    }
};