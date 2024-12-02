class Solution {
public:
    int isPrefixOfWord(string s, string word) {
        int cnt = 0;
        string sub = "", item, temp;
        vector<string> mp;
        stringstream ss(s);

        while(ss >> item) {
            mp.push_back(item);
        }
        for(int i = 0 ; i < mp.size(); i++) {
            temp = mp[i];
            if(temp.size() >= word.size()) {
                sub = temp.substr(0, word.size());
                if(sub == word) return i + 1;
            }
        }
        return -1;
    }
};