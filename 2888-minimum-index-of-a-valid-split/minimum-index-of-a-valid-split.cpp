class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        for(int i = 0 ; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto x: mp) {
            pq.push({x.second, x.first});
        }
        
        int top = pq.top().first, n = nums.size(), x, cnt = 0;

        while(!pq.empty() && top*2 > n) {            
            x = pq.top().second;
            cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] == x) cnt++;
                if(cnt*2 > i + 1) {
                    if((top - cnt)*2 > n - i - 1) return i;
                }
            }
            pq.pop();
            top = pq.top().first;
        }
        return -1;
    }
};