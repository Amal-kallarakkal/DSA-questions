class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> maxi;
        vector<string> ans;
        int n = words2.size(), m = words1.size();
        for(string s : words2) {
            map<char, int> mp;
            for( char i : s) {
                mp[i]++;
            }
            for(auto x : mp) {
                if(maxi[x.first] < x.second) {
                    maxi[x.first] = x.second;
                }
            }
        }
        
        for(string s : words1) {
            map<char, int> mp;
            for( char i : s) {
                mp[i]++;
            }
            ans.push_back(s);
            for(auto x : maxi) {
                if(mp[x.first] < x.second) {
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};