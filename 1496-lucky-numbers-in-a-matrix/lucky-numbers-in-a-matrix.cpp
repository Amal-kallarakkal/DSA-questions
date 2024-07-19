class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        unordered_set<int> rset;
        unordered_set<int> cset;
        unordered_set<int> set;
        vector<int> ans;
        int maxi, mini;

        for(int i = 0 ; i < row; i++) {
            mini = INT_MAX;
            for(int j = 0; j < col; j++) {
                mini = min(matrix[i][j] , mini);
            }
            
            rset.insert(mini);
        }

        for(int i = 0 ; i < col; i++) {
            maxi = 0;
            for(int j = 0; j < row; j++) {
                maxi = max(matrix[j][i] , maxi);
            }            
            cset.insert(maxi);
        }

        for(auto x: rset){
            if(cset.count(x)) set.insert(x);
        }
        
        for(auto x: cset){
            if(rset.count(x)) set.insert(x);
        }
        for(auto x: set){
            ans.push_back(x);
        }

        return ans;

    }
};