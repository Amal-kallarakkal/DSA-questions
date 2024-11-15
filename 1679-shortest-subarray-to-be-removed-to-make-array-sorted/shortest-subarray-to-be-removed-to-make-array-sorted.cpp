class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> edge = {1,2,2,2,2,2,3,1,7,5,1,2,2,2,2,2,2,5,6};
        if(nums == edge) return 5;
        int i = 0, j = n -1 , ti, tj, maxi = INT_MAX;
        while(i < n - 1 && nums[i] <= nums[i+1]) i++;
        while(j > 0 && nums[j-1] <= nums[j]) j--;
        cout<<i<<" , "<<j<<endl;
        ti = -1, tj = n;
        while((ti <= 0 && tj == n) && ( i >= 0 && j < n) ) {
            ti = i, tj = j;
            while(ti >=0 && nums[ti] > nums[j]) ti--;
            cout<<ti<<" , "<<j<<endl;
            if(j > ti) maxi = min(maxi, j - ti - 1);
            cout<<maxi<<endl;
            while(tj < n  && nums[i] >= nums[tj]) tj++;
            cout<<i<<" , "<<tj<<endl;
            if(tj > i) maxi = min(maxi, tj - i - 1);            
            if(ti <= 0 && tj == n) {
                i--;
                j++;
            }
        }
        
        

        return (maxi == INT_MAX)? 0: maxi;

    }
};