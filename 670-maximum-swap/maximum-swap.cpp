class Solution {
public:
    int maximumSwap(int num) {
        int maxi = 0;
        int mini = INT_MAX, j, k;
        vector<int> nums;
        while(num) {
            nums.push_back(num%10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        for(int x: nums) cout<<x;
        cout<<endl;
        k = -1, j = -1;
        for(int i = nums.size() - 1 ; i >= 0; i--) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                j = i;
            } else if(nums[i] < maxi) {
                k = i;
            }            
        }
        // cout<<k<<", "<<j<<endl;
        if(k < j && k > -1) swap(nums[k], nums[j]);
        for(int x: nums) num = num*10 + x;
        if(k < j && k > -1) swap(nums[k], nums[j]);

        int num2 = 0;
        k = -1, j = -1;
        maxi = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                k = i;
            } else if(nums[i] > mini) {
                if(maxi <= nums[i]) {
                    maxi = nums[i];
                    j = i;
                }
            }            
        }

        // cout<<k<<", "<<j<<endl;
        if(k < j && (j > -1 && k > -1)) swap(nums[k], nums[j]);
        for(int x: nums) num2 = num2*10 + x;
        // cout<<num2<<endl;
        return max(num, num2);
    }
};