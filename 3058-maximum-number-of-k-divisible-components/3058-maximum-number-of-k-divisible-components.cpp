class Solution {
public:
    int dfs(int x, vector<vector<int>>& adj, vector<int> &visited, vector<int>& values, int &k, int &cnt) {
        visited[x] = 1;
        int sum = values[x];
        for(int i : adj[x]) {
            if(!visited[i]) sum += dfs(i, adj, visited, values, k, cnt);
        }
        if(sum % k == 0) cnt++;
        // cout<<"node "<<x<<", sum: "<<sum<<endl;
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int cnt = 0;
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, adj, visited, values, k, cnt);
        return cnt;
    }
};