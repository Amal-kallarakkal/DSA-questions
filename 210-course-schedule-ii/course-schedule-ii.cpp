class Solution {
public:
    void dfs(int i, vector<int> &visited, vector<unordered_set<int>> &adj, vector<int> &ans) {
        visited[i] = 1;

        for(int j : adj[i]) {
            if(!visited[j]) {
                dfs(j, visited, adj, ans);
            }
        }
        ans.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
        int v = numCourses;
        vector<unordered_set<int>> adj(v);
        vector<int> visited(v, 0);
        vector<int> ans;

        for(int i = 0 ; i < nums.size(); i++) {
            adj[nums[i][1]].insert(nums[i][0]);
        }

        for(int i = 0 ; i < visited.size(); i++) {
            if(!visited[i]) {
                dfs(i, visited, adj, ans);
            }            
        }
       
        for(int i = 0; i < v ; i++) {
            for(int j = i ; j < v; j++) {
                if(adj[ans[i]].count(ans[j])) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};