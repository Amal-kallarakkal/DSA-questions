class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int i = 0 ;
        if(n == 1) {
            return words;
        }
          
        int j = i + 1;
           while(j< n) {
                    
                    if(groups[i] != groups[j]) {
                       if(ans.size()) {
                            ans.push_back(words[j]);
                        } else {

                           ans.push_back(words[i]);
                           ans.push_back(words[j]);
                        }
                        i = j;
                    } 
                    j++;
            }
            
        if(ans.size() == 0) ans.push_back(words[0]);
        return ans;
        
    }
};