class Solution {
public:

    bool cycleCheck(int i, vector<int> &visited, vector<vector<int>>& graph, vector<int> &path) {
        visited[i] = 1;
        path[i] = 1;

        for(int j: graph[i]) {
            if(!visited[j]) {
                if(cycleCheck(j, visited, graph, path)) return true;
            } else if(path[j]) {
                return true;
            }
        }
        path[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> ans;
        unordered_set<int> set;
        vector<int> visited(v, 0);
        vector<int> path(v, 0);        

        for(int i = 0 ; i < v; i++) {
            if(graph[i].size() == 0) {
                set.insert(i);
                ans.push_back(i);
            }
            for(int j: graph[i]) {                
                // check cycle present or not                    
                if(!cycleCheck(i, visited, graph, path)) {
                    if(!set.count(i)) {
                        ans.push_back(i);
                        set.insert(i);
                    }
                }            
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};