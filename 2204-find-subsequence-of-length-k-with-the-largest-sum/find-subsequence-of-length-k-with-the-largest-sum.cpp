class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);

        vector<int> ans(k);
        priority_queue<int> pq;
        map<int,vector<int> > mp;
        
        for(int i = 0 ; i < nums.size(); i++) {
            pq.push(nums[i]);
            mp[nums[i]].push_back(i);           
        }
        int i = 0;
        while(i < k) {
            int idx =  mp[pq.top()][mp[pq.top()].size() - 1];
            ans[i] = idx;
            if(mp[pq.top()].size()) mp[pq.top()].pop_back();
            pq.pop();
            i++;
        }
        sort(ans.begin(), ans.end());

        for(int i = 0; i < k; i++)  {

            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};