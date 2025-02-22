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
    int n, NextDash = 0; 
    TreeNode* solve(string &s, int &i, int PrevDash) {
        if(i >= n) return NULL;
        TreeNode * root = new TreeNode();
        int dash = 0, num;
        if(s[i] != '-') {
            num = 0;
            while(s[i] != '-' && i < n) {
                num = num*10 + (s[i] - '0');
                i++;
            }
            root->val = num;
        }
        while(s[i] == '-' && i < n) {
            i++;
            dash++;
        }
        if(dash <= PrevDash) {
            NextDash = dash;
            return root;
        } else {
            root->left = solve(s, i, dash);
            if(root->left && dash == NextDash) root->right = solve(s, i, dash);  
        } 
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0;
        TreeNode* root = solve(traversal, i, 0);
        return  root;
    }
};