using ll = long long;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        ll ans = 0;
        int j, n = nums.size();
        pair<int, int> top;
        vector<int> marked(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0 ; i < n; i++) {
            pq.push({nums[i], i});
        } 
        for(int i = 0 ; i < n; i++) {
            top = pq.top();
            pq.pop();
            j = top.second;
            if(marked[j]) continue;
            ans += top.first;
            for(int k = j - 1; k <= j+1; k++) {
                if(k >= 0 && k < n) marked[k] = 1;
            }
        }
        return ans;
    }
};