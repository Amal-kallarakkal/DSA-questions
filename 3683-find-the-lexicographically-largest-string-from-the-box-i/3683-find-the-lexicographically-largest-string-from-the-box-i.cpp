class Solution {
public:
    string answerString(string word, int nF) {
        string ans = "", curr = "";
        if(nF == 1) return word;
        int win = 1, n = word.size();
        for(int i = 0; i < n; i++) {
            ans = max(ans, word.substr(i, min(n - nF + 1, n - i)));
        }
            
        return ans;         
    }
};