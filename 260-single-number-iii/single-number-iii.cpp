using ll = long long int;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 2) return nums;
        ll abXor = 0;
        for(int i = 0; i < n; i++) {
            abXor ^= nums[i];            
        }
        // cout<<abXor<<endl;
        ll partition = 1;
        while(!(abXor & partition)) partition = partition<<1;

        // cout<<partition<<endl;
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