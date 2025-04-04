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
    void solve(int lvl, TreeNode* root, map<TreeNode*, TreeNode*> &parent, map<int, vector<TreeNode*>> &mp) {
        if(!root) return;
        mp[lvl].push_back(root);
        if(root->left) {
            parent[root->left] = root;
            solve(lvl + 1, root->left, parent, mp);
        }
        
        if(root->right) {
            parent[root->right] = root;
            solve(lvl+1, root->right, parent, mp);
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<int, vector<TreeNode*>> mp;
        map<TreeNode*, TreeNode*> parent;
        solve(0, root, parent, mp);

        // cout<<"last lvl: "<<(--mp.end())->first; 
        vector<TreeNode*> leaf = (--mp.end())->second;
        if(leaf.size() == 1) return leaf[0];
        else {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> set;
            TreeNode* temp;
            for(TreeNode* x: leaf) q.push(x);
            while(q.size() > 1) {
                temp = q.front();
                q.pop();

                if(parent.count(temp)) {
                    if(!set.count(parent[temp])) {
                        set.insert(parent[temp]);
                        q.push(parent[temp]);
                    }
                } 
            }
            return q.front();
        }
        return root;
    }
};