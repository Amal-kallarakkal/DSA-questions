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
    bool evaluateTree(TreeNode* root) {
        ios::sync_with_stdio(0);
        if(root == NULL) return NULL;
        if(root->val == 0) return false;
        if(root->val == 1) return true;

        int sum = 0;

        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);

        if(root->val == 2) sum = left + right;
        else sum = left*right;

        return sum? true: false;
    }
};