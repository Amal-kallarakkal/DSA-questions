class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();

        int i = 1;

        int sum = nums[0];
        
        while(i < n  && nums[i] == nums[i-1] +1) {
            sum += nums[i];
            i++;
        }
        
        sort(nums.begin(), nums.end());

        cout<<"sum: "<<sum<<endl;
        if(sum > nums[n-1] ) return sum;
        else if(sum == nums[n-1]) return sum + 1; 
        else {
            int i= 0;

            while(i < n && nums[i] <= sum ) {
                if(nums[i] == sum) sum++;
                i++;
            }

            
            return sum;

        }

        
    }
};