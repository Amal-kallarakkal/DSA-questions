class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        int ans = 0, row = mat.size(), col = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> rowarr(row), colarr(col);
        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            colarr[mp[arr[i]].second]++;
            rowarr[mp[arr[i]].first]++;
            if(colarr[mp[arr[i]].second] == row) return i;
            if(rowarr[mp[arr[i]].first] == col) return i;
        }
        return ans;
    }
};