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
        return (count.size() && !count.rbegin()->second.empty())?*(count.rbegin()->second.begin()): "";
    }
    
    string getMinKey() {
        return (count.size() && !count.begin()->second.empty())?*(count.begin()->second.begin()): "";
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */