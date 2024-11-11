class Solution {
public:
    int nextPrime(int n) {
        if(n == 0) return 2;
        int temp, j;
        for(int i = 1 ; i < 10; i++) {
            temp = n + i;
            j = 2;
            while(j*j <= temp) {
                if(temp%j == 0) break;
                j++;
            }
            if(j*j > temp) return temp;
        }
        return temp;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1 ; i > 0; i--) {
            if(nums[i-1] >= nums[i]) nums[i-1] -= nextPrime(nums[i-1] - nums[i]);
            if(nums[i-1] <= 0) return false;
        }
        return true;
    }
};