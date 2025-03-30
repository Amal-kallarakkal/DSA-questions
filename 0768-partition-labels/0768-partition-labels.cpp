class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> mp;
        int n = s.size(), maxi = 0, sum = 0;
        vector<int> ans;
        vector<vector<int>> nums;
        for(int i = 0 ; i < n ; i++) {
            if(!mp.count(s[i])) mp[s[i]].first = i;
            else mp[s[i]].second = i;
        }
        int i = 0; 
        for(auto x: mp) {
            nums.push_back({x.second.first, x.second.second});
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(maxi < nums[i][0]) ans.push_back(nums[i][0]);
            maxi = max(maxi, max(nums[i][0], nums[i][1]));
        }

        ans.push_back(maxi);
        for(int i = 1; i < ans.size(); i++) {
            sum += ans[i-1];
            ans[i] -= sum;
        }
        
        ans[ans.size() - 1]++;
        return ans;
    }
};