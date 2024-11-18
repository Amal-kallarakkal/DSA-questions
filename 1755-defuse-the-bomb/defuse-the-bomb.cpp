class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> circle , ans(n);
        if(!k) return ans;
        circle.insert(circle.begin(), code.begin(), code.end());
        circle.insert(circle.begin(), code.begin(), code.end());
        circle.insert(circle.begin(), code.begin(), code.end());

        for(int i = 0 ; i < n ; i++) {
            if(k > 0) ans[i] = accumulate(circle.begin() + i + 1, circle.begin() + i + k + 1, 0);
            else ans[i] = accumulate(circle.begin() + n + i + k, circle.begin() + n + i  , 0);
        }

        return ans;
    }
};