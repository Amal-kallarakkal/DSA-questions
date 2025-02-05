class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), cnt = 0;
        unordered_map<char, int> mp1, mp2;
        if(n1 != n2) return false;
        for(int i = 0 ; i < n1; i++){
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 2) return false;
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(mp1 == mp2) return true;

        return false;
    }
};