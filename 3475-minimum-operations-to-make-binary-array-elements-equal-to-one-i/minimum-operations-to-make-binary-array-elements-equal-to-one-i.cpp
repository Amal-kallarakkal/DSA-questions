#pragma GCC optimize("OFast")
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int n = nums.size();
        int st = 0;
        int end;
        int ans = 0;
        while(st < n) {
            end = st;
            if(nums[st] == 0) {
                // cout<<st<<endl;
                if(st + 3 > n) return -1;
                while(end < st + 3) {
                    nums[end] = !nums[end];
                    end++;
                }
                ans++;
            }
            st++;
        }
        
        return ans;
    }
};