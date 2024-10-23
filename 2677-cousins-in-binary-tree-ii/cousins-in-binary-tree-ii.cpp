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
    void solve(TreeNode* root, vector<int> &sum, int level) {
        if(!root) return;
        if(level >= sum.size()) {
            sum.push_back(root->val);
        } else sum[level] += root->val;

        solve(root->left, sum, level + 1);
        solve(root->right, sum, level + 1);

    }

    void solve2(TreeNode* root, vector<int> &sum, int level) {
        if(!root) return;
        int sibsum = 0;
        if(root->left) sibsum += root->left->val;
        if(root->right) sibsum += root->right->val;

        if(root->left) root->left->val = sum[level + 1] - sibsum;
        if(root->right) root->right->val = sum[level + 1] - sibsum;
        // cout<<root->val<<" : children"<<endl;
        // cout<<sibsum<<endl;

        solve2(root->left, sum, level + 1);
        solve2(root->right, sum, level + 1);

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return NULL;
        vector<int> sum;
        solve(root, sum, 0);
        solve2(root, sum, 0);
        root->val = 0;
        return root;
    }
};