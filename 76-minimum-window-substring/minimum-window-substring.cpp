class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        string ans = "";
        int ind = 0;
        int mini = INT_MAX;
        if(tn > sn ) return ans;
        map<int,int> mp;
        int cnt = tn;

        int i = 0 ,j = 0;

        for(int i = 0 ; i < tn; i++) mp[t[i]]++;

        while(j < sn) {
            
            if(mp[s[j]] > 0) cnt--;
            mp[s[j]]--;

            while(i <= j && cnt == 0) {
                if(j - i + 1 < mini) {
                    mini = j - i + 1;
                    ind = i;                    
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt++;
                i++;                    
            }
            j++;
        }
        
        

        if(mini < INT_MAX) ans = s.substr(ind, mini);
        return ans;
    }
};