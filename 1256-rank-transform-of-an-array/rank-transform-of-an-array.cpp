class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> ans(arr.size());
        unordered_map<int, int> rank;
        for(int i = 0 ; i < arr.size(); i++)    {
            mp[arr[i]]++;
        }
        int i = 1;
        for(auto x : mp) {
            rank[x.first] = i++;
        }
        for(int i = 0; i < arr.size(); i++ ) {
            ans[i] = rank[arr[i]];
        }

        return ans;

    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();