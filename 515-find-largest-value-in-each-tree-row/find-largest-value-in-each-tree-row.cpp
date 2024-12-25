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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int n, maxi;
        TreeNode* temp;
        

        while(!q.empty()) {
            n = q.size();
            maxi = -INT_MAX - 1;
            
            for(int i = 0 ; i < n; i++) {
                temp = q.front();
                if(temp == NULL) return ans;
                q.pop();
                maxi = max(temp->val, maxi);
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};