#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        priority_queue<pair<int, string>> pq;
        int n = names.size();
        for(int i = 0; i < n; i++) {
            pq.push({heights[i],names[i]});
        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};