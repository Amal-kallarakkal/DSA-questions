#pragma GCC optimize("OFast")
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios::sync_with_stdio(0);
        // cin.tie(false);
        // cout.tie(false);
        string ans = strs[0];
        
        string temp = "";
        for(int i = 1 ; i < strs.size(); i++) {
            temp = "";
            for(int j = 0; j < strs[i].size(); j++) {
                if(ans[j] != strs[i][j]) break;                
                temp += ans[j];
            }
            ans = temp;
        }
        return ans;
    }
};