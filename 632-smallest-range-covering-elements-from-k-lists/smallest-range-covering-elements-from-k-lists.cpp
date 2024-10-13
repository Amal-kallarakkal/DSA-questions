class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      vector<int> ans(2) , mxtop(3), mntop(3);
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_pq;
      priority_queue<vector<int>> max_pq;
      for(int i = 0 ; i < nums.size(); i++) {
        min_pq.push({nums[i][0], i, 0});
        max_pq.push({nums[i][0], i, 0});
      }
      int i = 0, j = 0, diff = INT_MAX, low, hi;
      while(!min_pq.empty()) {
        mxtop = max_pq.top();
        mntop = min_pq.top();
        low = mntop[0];
        hi = mxtop[0];
        if(hi - low < diff) {
            diff = hi - low;
            ans[0] = low;
            ans[1] = hi;
        }
        i = mntop[1];
        j = mntop[2];
        if(j + 1 >= nums[i].size()) break;
        min_pq.pop();
        min_pq.push({nums[i][j+1], i, j+1});
        max_pq.push({nums[i][j+1], i, j+1});
      }

      return ans;

    }
};