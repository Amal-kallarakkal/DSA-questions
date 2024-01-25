class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        if(n1 != n2) return false;

        map<char, int> mp1;
        map<char,int> mp2;
        for(int i = 0; i < n1; i++) mp1[s[i]]++;
        for(int i = 0 ; i < n2 ; i++) mp2[t[i]]++;

        if(mp1.size() != mp2.size()) return false;

        for(auto x : mp1) {
            if(mp2.find(x.first) != mp2.end()) {
                if(mp2[x.first] != x.second) return false;
            } else {
                false;
            }
        }

        for(auto x : mp2) {
            if(mp2.find(x.first) != mp2.end()) {
                if(mp1[x.first] != x.second) return false;
            } else {
                false;
            }
        }

        return true;


    }
};