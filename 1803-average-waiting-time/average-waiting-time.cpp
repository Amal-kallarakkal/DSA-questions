class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> wait(n, 0);
        int time = 0;
        // wait[0] = nums[0][1];
        int w = 0;
        for(int i = 0; i < n ; i++) {
            
            if(time <= nums[i][0] ){
                time += nums[i][1] - (time - nums[i][0]);
            }  else {
                time += nums[i][1];
            }
                w = time - nums[i][0];
                // cout<<time<<" - "<<nums[i][0]<<" = "<<w<<endl;          

            wait[i] = w;
        }
        long long int sum = 0;
        double avg = (accumulate(wait.begin(), wait.end(), sum))*1.0/n;
        return avg;
    }
};