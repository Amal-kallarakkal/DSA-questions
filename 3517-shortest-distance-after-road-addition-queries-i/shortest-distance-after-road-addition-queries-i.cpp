class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size(), D, curr;
        vector<int> ans(m), dist(n);
        vector<vector<int>> adj(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n - 1; i++) adj[i].push_back(i+1);
        for(int i = 0 ; i < n; i++) dist[i] = i;
        for(int i = 0 ; i < m; i++) {
            // dist, node
            adj[queries[i][0]].push_back(queries[i][1]);
            pq.push({dist[queries[i][0]], queries[i][0]});

            while(!pq.empty()) {
                curr = pq.top().second, D = pq.top().first;
                pq.pop();
                for(int x : adj[curr]) {
                    if(dist[x] > D + 1) {
                        dist[x] = D + 1;
                        pq.push({dist[x], x});
                    }
                }
            }
            ans[i] = dist[n-1];

        }

        return ans;
    }
};