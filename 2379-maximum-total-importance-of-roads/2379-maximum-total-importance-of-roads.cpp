#pragma GCC optimize("OFast")
using ll = long long;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int,int> mp;
        ll sum = 0;
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < roads.size(); i++) {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        for(auto x: mp) {
            pq.push({x.second, x.first});
        }

        while(!pq.empty()) {
            pair<int,int> x;
            x = pq.top();
            pq.pop();
            mp[x.second] = n--;
            
        }

        for(int i = 0 ; i < roads.size(); i++) {
           sum += mp[roads[i][0]] + mp[roads[i][1]] ;
        }
        return sum;

    }
};