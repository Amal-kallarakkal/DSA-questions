#pragma GCC optimize("OFast")
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios::sync_with_stdio(0);
        
        string ans = "";

        int start = 0;
        int end = start + 1;
        unordered_map<string, int> mp;
        for(int i = 0 ; i < dictionary.size(); i++) mp[dictionary[i]]++;

        string t = "";
        string tt = "";
        while(start < sentence.size()) {
            end = start +1;
            while(end < sentence.size() && sentence[end] != ' ' ) {
                end++;
            }
            t = sentence.substr(start, end - start);
            for(int j = 0 ; j < t.size(); j++ ) {
                tt += t[j];
                if(mp.count(tt)) {
                    break;
                }
            }
            if(tt == "" ) {
                if(ans == "")  ans += t;
                else ans += " " + t;
            }    
            else {
                if(ans == "")  ans += tt;
                else ans += " " + tt;
            }    
            tt = "";
            start = end + 1;
        }

        return ans;
    }
};