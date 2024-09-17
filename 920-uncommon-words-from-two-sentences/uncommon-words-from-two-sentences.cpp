#include <sstream>
#include<bits/stdc++.h>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        vector<string> ans;

        stringstream ss(s1); 
        string token; 
            
        while (getline(ss, token, ' ')) { 
            mp1[token]++;
        }
        
        stringstream ss2(s2);

        while (getline(ss2, token, ' ')) { 
            mp1[token]++;
        } 

        for(auto x : mp1) {
            if(x.second == 1) {
                ans.push_back(x.first);
            }
        }

        return ans;

    }
};

static int const speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();