class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        int v = numCourses;
        vector<unordered_set<int>> adj(v);
        vector<int> indegree(v, 0);
        queue<int> q;
        vector<int> ans;

        for(int i = 0 ; i < nums.size(); i++) {
            adj[nums[i][1]].insert(nums[i][0]);
        }

        for(int i = 0 ; i < v; i++) {
            for(int j: adj[i]) {
                indegree[j]++;
            }
        }
       
        for(int i = 0; i < v ; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }

        int f ;
        while(!q.empty()) {
            f = q.front();
            ans.push_back(f);
            q.pop();

            for(int i: adj[f]) {
                indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
        }
        return (ans.size() == v);

    }
};