class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> mp;
        int n = score.size();
        vector<string> ans(n);

        for(int i = 0 ; i < score.size(); i++) {
            mp[score[i]] = i ;            
        }
        int i = n - 1;

        // for(auto x : mp) cout<<x

        for(auto x : mp)  {
           if(i == 0) ans[x.second] = "Gold Medal";
           else if(i == 1) ans[x.second] = "Silver Medal";
           else if(i == 2) ans[x.second] = "Bronze Medal";

           else {
                ans[x.second] = to_string(i + 1);
           }
           i--;
        }

        return ans;
    }
};