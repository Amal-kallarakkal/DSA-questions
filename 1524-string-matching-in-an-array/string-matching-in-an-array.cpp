class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        string temp;

        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if(j == i) continue;
                if(words[i].size() > words[j].size()) continue;
                else if(words[i].size() == words[j].size() && words[j] == words[i]) {
                    ans.push_back(words[i]);
                    break;
                } 

                for(int k = 0; k < words[j].size() - words[i].size() + 1; k++) {
                    temp = words[j].substr(k, words[i].size());
                    if(temp == words[i]) {
                        ans.push_back(words[i]);
                        break;
                    }
                }
                if(temp == words[i]) break;
            }
        }
        
        return ans;
    }
};