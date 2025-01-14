class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> ans(n), set(n + 1);
        for(int i = 0 ; i < n; i++) {
            if(set[A[i]] > 0) cnt++;
            else set[A[i]]++;
            if(set[B[i]] > 0) cnt++;
            else set[B[i]]++;
            ans[i] = cnt;
        }
        return ans;
    }
};