class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int k = 0;
        if(original.size() !=  n*m) return ans;
        
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            ans.push_back(temp);
            for(int j = 0 ; j < n; j++) {
                ans[i].push_back(original[k++]);
            }
        }

        return ans;
    }
};