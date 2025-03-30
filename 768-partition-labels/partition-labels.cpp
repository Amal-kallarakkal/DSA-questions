class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n = s.size(), maxi = 0, sum = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]] = i;
        }
       
        for(int i = 0; i < n; i++) {
            if(maxi < i) ans.push_back(i);
            maxi = max(maxi, mp[s[i]]);
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