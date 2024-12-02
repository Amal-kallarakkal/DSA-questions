class Solution {
public:
    int isPrefixOfWord(string s, string word) {
        int cnt = 0;
        string sub = "", item, temp;
        map<int, string> mp;
        stringstream ss(s);

        while(ss >> item) {
            mp[++cnt] = item;
        }
        for(auto i : mp) {
            // cout<<i.first<<" : "<<i.second<<endl;
            temp = i.second;
            if(temp.size() >= word.size()) {
                sub = temp.substr(0, word.size());
                if(sub == word) return i.first;
            }
        }
        return -1;
    }
};