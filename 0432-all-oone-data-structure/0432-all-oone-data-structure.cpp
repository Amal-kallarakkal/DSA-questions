class AllOne {
public:
    map<string, int> mp;
    map<int, set<string>> count;
    AllOne() {
        
    }
    
    void inc(string key) {
        int cnt = mp[key];
        if(cnt) {
            if(count[cnt].count(key)) {
                count[cnt].erase(key);
            }
        }
        if(count[cnt].empty()) count.erase(cnt);
        mp[key]++;
        count[mp[key]].insert(key);
    }
    
    void dec(string key) {
        int cnt = mp[key];
        if(cnt) {
            if(count[cnt].count(key)) {
                count[cnt].erase(key);
            }
        }
        if(count[cnt].empty()) count.erase(cnt);
        mp[key]--;
        if(mp[key] == 0) mp.erase(key);        
        else count[mp[key]].insert(key);
    }
    
    string getMaxKey() {
        string ans = "";
        auto maxFreqIt = count.rbegin();
        if(count.size() && !maxFreqIt->second.empty()) ans =  *(maxFreqIt->second.begin());
        return ans;
    }
    
    string getMinKey() {
        string ans = "";
        auto minFreqIt = count.begin();
        if(count.size() && !minFreqIt->second.empty()) ans =  *(minFreqIt->second.begin());
        return ans;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();