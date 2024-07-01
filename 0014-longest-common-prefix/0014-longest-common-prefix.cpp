class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        // sort(strs.begin(), strs.end());
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