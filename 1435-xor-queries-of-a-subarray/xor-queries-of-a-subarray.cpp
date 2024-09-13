class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        for(int i =0 ; i < n ; i++) {            
            for(int j = queries[i][0]; j <= queries[i][1]; j++) {
                ans[i] ^= arr[j];
            }
        }
        
        return ans;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();