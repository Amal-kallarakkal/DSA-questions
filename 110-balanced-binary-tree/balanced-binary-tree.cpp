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

    int Height(TreeNode* root) {
        if(!root) return 0;
        int lh = Height(root->left) + 1;
        int rh = Height(root->right) + 1;

        return max(lh, rh);
    }

    void solve(TreeNode* root, bool &flag) {
        if(!root) return;

        if(flag) {
            solve(root->left, flag);
            solve(root->right, flag);

            int lh = Height(root->left);
            int rh = Height(root->right);
            cout<<"height diff for node "<<root->val<<" Node : "<<abs(rh - lh)<<endl;
            // flag = abs(rh - lh) <= 1 ? true : false;
            int diff = abs(rh - lh);
            if(diff > 1) flag = false;
            
        }

    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag = true;

        solve(root, flag);

        return flag;
    }
};