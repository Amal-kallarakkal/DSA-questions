class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> ans(n);
        unordered_set<int> set;
        for(int i = 0 ; i < n; i++) {
            if(set.count(A[i])) cnt++;
            else set.insert(A[i]);
            if(set.count(B[i])) cnt++;
            else set.insert(B[i]);
            ans[i] = cnt;
        }
        return ans;
    }
};