class Solution {
public:
    void solve(int i , vector<int> &ans, int &n) {
        if(i > n) return ;
        ans.push_back(i);
        if(i == n) return;

        for(int j = 0; j < 10; j++ ) {
            solve(i*10 + j, ans, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<vector<int>> mp(9);
        vector<int> ans;
        for(int i = 1; i < 10; i++) {
            solve(i, ans, n);
        }
        return ans;
    }
};

static const int speedup = [](){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

