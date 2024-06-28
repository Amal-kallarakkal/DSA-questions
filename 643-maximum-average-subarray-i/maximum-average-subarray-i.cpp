class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int sum = 0;
        int j = 0;
        double maxi = 0;

        for(int i = 0; i < k; i++) sum += nums[i];

        maxi = ((sum)*1.0)/k;
        // cout<<sum<<endl;
        for(int i = 0  ; i < nums.size() - k   ; i++) {
            j = i + k;
            // cout<<"before: "<<sum<<endl;
            sum -= nums[i];
            // cout<<"middle: "<<sum<<endl;
            sum += nums[j];
            ans = ((sum)*(1.0))/k;
            // cout<<"after: "<<sum<<endl;
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};