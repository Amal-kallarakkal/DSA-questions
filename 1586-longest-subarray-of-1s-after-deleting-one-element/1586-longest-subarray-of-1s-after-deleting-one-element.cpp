#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class Solution {
public:
    // ios::sync_with_stdio(0);
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0, i = 0 , j = 0, n = nums.size();

        while(i < n) {
           while(cnt <= 1 && j < n) {
                if(!nums[j]) cnt++;                
                j++;
           }
           maxi = (cnt)? max(maxi, j - i - cnt): max(maxi, j - i - 1);
           if(!nums[i]) cnt--;
           i++;
        }
        return maxi;
    }
};