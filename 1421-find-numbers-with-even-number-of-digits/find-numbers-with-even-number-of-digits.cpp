class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0, n = nums.size(), cnt, m;

        for(int i = 0 ; i < n; i++) {
            cnt = 0;
            m = nums[i];
            while(m) {
                m /= 10;
                cnt++;
            }
            if(cnt%2 == 0) ans++;
        }

        return ans;
    }
};