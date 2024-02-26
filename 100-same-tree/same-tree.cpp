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

    void recur(TreeNode* root, string &s){
        if(!root){
            s+="N ";
            return;
        }

        s+= to_string(root->val)+" ";

        recur(root->left, s);
        recur(root->right, s);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string a="", b="";

        recur(p, a);
        recur(q, b);

        return a==b;
    }
};