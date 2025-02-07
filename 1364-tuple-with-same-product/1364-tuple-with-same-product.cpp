class Solution {
public:
    int nC2(int n) {
        if(n <= 2) return n;
        return n*(n-1);
    }
    int tupleSameProduct(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n-1; i++) {
            for(int j = i+1 ; j < n; j++) mp[nums[i]*nums[j]]++;
        }
        for(auto x : mp) {
            if(x.second > 1) {
                cnt += nC2(x.second); 
            }
        }
        return cnt*4;
    }
};