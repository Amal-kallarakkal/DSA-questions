class Solution {
public:
    
    int tupleSameProduct(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n-1; i++) {
            for(int j = i+1 ; j < n; j++) mp[nums[i]*nums[j]]++;
        }
        for(auto x : mp) {
            if(x.second > 1) {
                cnt += (x.second)*(x.second - 1); 
            }
        }
        return cnt*4;
    }
};