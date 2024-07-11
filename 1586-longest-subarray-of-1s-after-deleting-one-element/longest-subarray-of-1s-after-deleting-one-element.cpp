class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0, i = 0 , j = 0, n = nums.size();

        while(i < n) {
           cout<<i<<" , "<<j<<" , "<<cnt<<endl;
           while(cnt <= 1 && j < n) {
                if(!nums[j]) cnt++;
                // if(cnt > 1) break;
                j++;
           }
           maxi = (cnt)? max(maxi, j - i - cnt): max(maxi, j - i - 1);

        //    j++;
           if(!nums[i]) cnt--;
           i++;
        }
        return maxi;
    }
};