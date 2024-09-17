#include <sstream>
#include<bits/stdc++.h>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        vector<string> ans;

        stringstream ss(s1); 
        string token; 
            
        while (getline(ss, token, ' ')) { 
            mp1[token]++;
        }
        
        stringstream ss2(s2);

        while (getline(ss2, token, ' ')) { 
            mp2[token]++;
        } 

        for(auto x : mp1) {
            if(x.second < 2) {
                if(!mp2.count(x.first)) ans.push_back(x.first);
            }
        }

        for(auto x : mp2) {
            if(x.second < 2) {
                if(!mp1.count(x.first)) ans.push_back(x.first);
            }
        }

        return ans;

    }
};