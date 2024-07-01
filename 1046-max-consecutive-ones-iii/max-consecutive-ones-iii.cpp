#pragma GCC optimize("OFast")
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int cnt = 0;
        int ans = 0;
        int maxi = 0;
        int j = 0;
        for(int i = 0 ; i < nums.size()  - maxi; i++) {
            
            while(j < nums.size() && cnt <= k) {
                if(!nums[j])cnt++;
                if(cnt > k) {
                    cnt--;
                    break;
                }
                j++;                
            }            
            ans = j - i ;
            maxi = max(maxi, ans);
            if(!nums[i]) cnt--;
            
        }
        return maxi;
    }
};