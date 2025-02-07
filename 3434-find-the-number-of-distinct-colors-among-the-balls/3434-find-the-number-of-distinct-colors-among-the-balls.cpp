class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        
        unordered_map<int,int> color;
        unordered_map<int,int> ball;
        vector<int> ans(n);
        
        for(int i = 0; i < n ; i ++) {
            if(ball[queries[i][0]] == 0) {
                ball[queries[i][0]] = queries[i][1];
                color[queries[i][1]]++;
            } else {
                color[ball[queries[i][0]]]--;
                if(color[ball[queries[i][0]]] == 0) color.erase(ball[queries[i][0]]);
                ball[queries[i][0]] = queries[i][1];
                color[queries[i][1]]++; 
            } 
            
            
            ans[i] =  color.size();
        }
        
        return ans;
    }
};