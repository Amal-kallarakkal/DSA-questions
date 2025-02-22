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
class FindElements {
public:
    unordered_set<int> set;
    void solve(int x, TreeNode * root) {
        if(!root) return;
        root->val =  x;
        set.insert(x);
        if(root->left) solve(x*2 + 1, root->left);
        if(root->right) solve(x*2 + 2, root->right);
    }
    FindElements(TreeNode* root) {
        solve(0, root);
    }
    
    bool find(int target) {
        return (set.count(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */