using ll = long long int;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int n = nums.size();        
        if(n == 2) return nums;

        ll abXor = 0;
        for(int i = 0; i < n; i++) {
            abXor ^= nums[i];            
        }
       
        ll partition = 1;
        while(!(abXor & partition)) partition = partition<<1;

        int a = 0;
        int b = 0;
        for(int i = 0; i < n ; i++) {
           if(nums[i]&partition) {
                a ^= nums[i];
           } else {
                b ^= nums[i];
           }
        }
        
        return {a, b};
    }
};