class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int cnt = 0, n = words.size(), m = queries.size(); 
        vector<int> nums(n), ans(m);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++) {
            if(vowels.count(words[i][0])&&vowels.count(words[i][words[i].size()-1])) {
                cnt++;                
            }
            nums[i] = cnt;
        }
        for(int i = 0 ; i < m ; i++) {
            if(queries[i][0] == 0) ans[i] = nums[queries[i][1]];
            else ans[i] = nums[queries[i][1]] - nums[queries[i][0] - 1];
        }
        return ans;
    }
};