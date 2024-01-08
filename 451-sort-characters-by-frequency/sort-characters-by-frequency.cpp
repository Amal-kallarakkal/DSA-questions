class Solution {
public:
    string frequencySort(string s) {

        map<char,int> mp;
        int maxi = 0;
        for(int i = 0 ; i < s.size(); i++) {
            mp[s[i]]++;
            maxi = max(maxi,mp[s[i]]);
        }
        
        string ans = "";
        while(maxi) {
            for(auto x : mp) {
                if(x.second == maxi) {
                   int j = 0;
                    while(j<x.second) {
                        j++;
                        ans += x.first;
                    }

                }
            }
            maxi--;
        }
        
        
        return ans;
    }
};