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
class Solution {
public:
    void solve(TreeNode* root, int &sum) {
        if(!root) return;

        // leaf node
        if(!root->left && !root->right) {
            sum += root->val; 
            root->val = sum;
            return;
        }
        // rightmost
        solve(root->right, sum);

        sum += root->val;
        // cout<<sum<<"for node:"<<root->val<<endl;
        root->val = sum;
        // leftmost
        solve(root->left, sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};