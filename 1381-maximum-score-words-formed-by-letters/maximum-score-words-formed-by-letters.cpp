class Solution {
public:
    int solve(int idx, vector<string>& words, vector<int>& score,  map<char, int> &ltr, int &ans){

        if(idx >= words.size()) return ans;

        // icluding the current string
        int scores = 0;
        string incomp = "";  
       
        for(int i = 0; i <words[idx].size(); i++ ) {
            if(ltr[words[idx][i]] != 0) {
                incomp += words[idx][i];
                scores += score[words[idx][i] - 97];
                ltr[words[idx][i]]--;
            } else {
                scores = 0;
                for(int j = 0 ; j < incomp.size(); j++) {
                    ltr[incomp[j]]++;
                }
                incomp = "";               
                break;
            }
        }

        ans += scores;
        int inc = solve(idx + 1, words, score, ltr, ans);

        // backtrack
        for(int j = 0 ; j < incomp.size(); j++) {
            ltr[incomp[j]]++;
        }
        ans -= scores;
        
        int exc = solve(idx + 1, words, score, ltr, ans);

        return  max(inc , exc);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        ios::sync_with_stdio(0);

        map<char, int> ltr;
        
        // limited letters count map
        for (int i = 0; i < letters.size(); i++) {
            ltr[letters[i]]++;
        }
        int ans = 0;
        int finans = solve(0, words, score, ltr, ans);

        
        return finans;
    }
};