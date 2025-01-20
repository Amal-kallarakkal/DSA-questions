class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int ans = 0, row = mat.size(), col = mat[0].size();
        vector<vector<int>> mp(arr.size() + 1);
        vector<int> rowarr(row), colarr(col);
        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            rowarr[mp[arr[i]][0]]++;
            colarr[mp[arr[i]][1]]++;
            if(colarr[mp[arr[i]][1]] == row) return i;
            if(rowarr[mp[arr[i]][0]] == col) return i;
        }
        return ans;
    }
};