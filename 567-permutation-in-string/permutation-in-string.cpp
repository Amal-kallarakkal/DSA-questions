class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s2.size() < n) return false;
        vector<int> mp(26, 0);
        
        for(int i = 0 ; i < n ; i++) mp[s1[i] - 'a']++;

        for(int i = 0 ; i < s2.size() - n + 1; i++) {
            vector<int> temp(26, 0);
            if(mp[s2[i] - 'a']) {                
                for(int j = i ; j < i+ n ; j++) {
                    if(!mp[s2[j] - 'a']) break;
                    temp[s2[j] - 'a']++;
                }
                if(temp == mp) return true;
            }
        }

        return false;
    }
};

