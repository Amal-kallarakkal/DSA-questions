/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
// -----------------------------------SOLUTION USING MORRIS TRAVERSAL, O(1) SPACE COMPLEXITY------------------------
        TreeNode* curr = root;
        TreeNode* prev;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // go to the rightmost node (of the left subtree)
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                // check if prev-> right is NULL or not

                if (prev->right == NULL) {
                    prev->right = curr;
                    // move the curr to its left
                    curr = curr->left;
                } else {
                    // if prev->right == curr, push curr into ans(which means we
                    // are inserting a root node) and cut the link between curr and prev.
                    ans.push_back(curr->val);
                    prev->right = NULL;

                    // mving onto the Right- subtree/node
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};