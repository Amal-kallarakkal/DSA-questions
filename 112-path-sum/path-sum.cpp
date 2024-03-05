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

    void solve(TreeNode* root, bool &flag, int target, int sum = 0) {
        if(!root) return;
        if(flag) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            sum += root->val;
            if(sum == target) flag = true;
            else  sum -= root->val;           
            return;
        }
        if(root->left) solve(root->left, flag, target, sum + root->val);
        
        if(root->right) solve(root->right, flag, target, sum + root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;

        solve(root, flag, targetSum);

        return flag;
    }
};