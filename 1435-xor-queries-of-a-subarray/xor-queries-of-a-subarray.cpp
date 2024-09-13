class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i = 1 ; i < arr.size(); i++) {
            prefix[i] = arr[i]^prefix[i-1];
        }

        for(int i =0 ; i < n ; i++) {            
            if(queries[i][0] == 0) {
                ans[i] = prefix[queries[i][1]];
            } else {
                int a = prefix[queries[i][1]]^prefix[queries[i][0] - 1];
                ans[i] = a;
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