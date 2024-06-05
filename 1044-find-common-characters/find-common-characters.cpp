class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios::sync_with_stdio(0);

        sort(words.begin(), words.end());

        for(int i = 0 ; i < words.size(); i++) {
            sort(words[i].begin(), words[i].end());
        }

        string res = words[0];

        for(int i = 1 ; i < words.size(); i++) {
            int ri = 0;
            int j = 0;
            string update ="";

            while(j < words[i].size() && ri < res.size() ) {
                // cout<<words[i][j]<<" "<<res[ri]<<endl;
                if(words[i][j] == res[ri]) {
                    // cout<<res[ri]<<endl;
                    update += res[ri];
                    ri++;
                    j++;
                } else if(words[i][j] > res[ri]) {
                    ri++;
                } else j++;
                // cout<<update<<endl;
                
            }
            res = update;
        }
        vector<string> ans(res.size());
        for(int  i = 0 ; i < res.size(); i++) {
            ans[i] = res[i];
        }

        return ans;
    }
};