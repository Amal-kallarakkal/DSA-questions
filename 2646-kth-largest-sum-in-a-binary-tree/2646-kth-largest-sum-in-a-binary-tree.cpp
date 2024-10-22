/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 using ll = long long;
class Solution {
public:
    void solve(TreeNode* root, vector<ll> &sum, int level,  int k) {
        if(!root) return;
        
        if(sum.size() <= level) sum.push_back(root->val);
        else sum[level] += root->val;
        solve(root->left, sum, level + 1, k);
        solve(root->right, sum, level + 1, k);
    }


    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> sum;
        ll ans = - 1;
        solve(root, sum, 0, k);
        sort(sum.rbegin(), sum.rend());
        if(k <= sum.size()) ans = sum[ k - 1] ;
        return ans;
    }
};