class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt= 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt%2) nums[i] = !nums[i];
            if(!nums[i]) cnt++;
        }
        return cnt;
    }
};