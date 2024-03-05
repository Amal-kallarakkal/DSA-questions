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
    string LeftFace(TreeNode* root) {
        string s = "";
        if(!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left) {
                q.push(temp->left);
                s += to_string(temp->left->val);
            }else {
                s += "N";
            }
            if(temp->right) {
                q.push(temp->right);
                s += to_string(temp->right->val);
            } else {
                s += "N";
            }
        }

        return s;
    }

    string RightFace(TreeNode* root) {
        string s = "";
        if(!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->right) {
                q.push(temp->right);
                s += to_string(temp->right->val);
            }else {
                s += "N";
            }
            if(temp->left) {
                q.push(temp->left);
                s += to_string(temp->left->val);
            } else {
                s += "N";
            }
        }

        return s;
    }
    bool isSymmetric(TreeNode* root) {
        string L = LeftFace(root->left);
        string R = RightFace(root->right);
        cout<<"l:"<< L<<endl<<"r: "<<R<<endl;
        if(L == R) return true;
        return false;
    }
};