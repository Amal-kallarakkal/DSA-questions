class Solution {
public:
    int solve(int idx, vector<string>& words, map<char, int> &mp,  map<char, int> &ltr, int ans){

        if(idx >= words.size()) return ans;

        // icluding the current string
        int score = 0;
        string incomp = "";        
       
        // // cout<<"before backtracking for "<<words[idx]<<" : "<<endl;

        // for(auto x : ltr) cout<<x.first<<" : "<<x.second<<" ";

        for(int i = 0; i <words[idx].size(); i++ ) {
            if(ltr[words[idx][i]] != 0) {
                incomp += words[idx][i];
                score += mp[words[idx][i]];
                ltr[words[idx][i]]--;
            } else {
                score = 0;
                for(int j = 0 ; j < incomp.size(); j++) {
                    ltr[incomp[j]]++;
                }
                incomp = "";
                // cout<<words[idx]<<" cant be formed with given letters"<<endl;
                break;
            }
        }

        ans += score;
        // cout<<"score for "<<words[idx]<<": "<<ans<<endl;
        int inc = solve(idx + 1, words, mp, ltr, ans);

        // cout<<"include "<<words[idx]<<" : "<<inc<<endl;
        // backtrack
        for(int j = 0 ; j < incomp.size(); j++) {
            ltr[incomp[j]]++;
        }
        ans -= score;
        

        int exc = solve(idx + 1, words, mp, ltr, ans);
        // cout<<"exclude "<<words[idx]<<" : "<<exc<<endl;

        return  max(inc , exc);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxi = 0;
        map<char, int> mp;
        map<char, int> ltr;
        char a = 'a';
        // score map
        for (int i = 0; i < 26; i++) {
            mp[a++] = score[i];
        }
        // limited letters count map
        for (int i = 0; i < letters.size(); i++) {
            ltr[letters[i]]++;
        }
        int ans = 0;
        int finans = solve(0, words, mp, ltr, ans);

        
        return finans;
    }
};