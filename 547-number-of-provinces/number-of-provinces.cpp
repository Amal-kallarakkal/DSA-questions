class Solution {
public:
    void bfs(int start, vector<int> &visited, vector<vector<int>> &g) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int front ;
        while(!q.empty()) {
            front = q.front();
            q.pop();
            // cout<<front<<" ";
            for(int x: g[front]) {
                if(!visited[x]) {
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        // cout<<endl;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;

        vector<int> visited(n,0);
        vector<vector<int>> g(n);
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j]) {
                    g[i].push_back(j);                
                    g[j].push_back(i);
                }                
            }
        }
        
        for(int i = 0 ; i < n; i++) {            
            if(visited[i] == 0) {
                cnt++;
                // cout<<"bfs: "<<endl;
                bfs(i, visited, g);
            }
        }

        return cnt;
    }
};
