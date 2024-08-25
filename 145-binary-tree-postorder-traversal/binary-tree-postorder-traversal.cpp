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
     vector<int> ans;

    void solve(TreeNode* root) {
        // post order {left, right , root}
        if(root == NULL) return;

        // left
        if(root->left) solve(root->left);

        // right
        if(root->right) solve(root->right);

        // root
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {     
        
        solve(root);
        return ans;
    }
};