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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int root;
        unordered_set<int> set;
        int n = descriptions.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < n; i++) {
            if(!mp.count(descriptions[i][0])) mp[descriptions[i][0]] = vector<int> (2,-1);
            if(descriptions[i][2]) mp[descriptions[i][0]][0] = descriptions[i][1] ;
            else mp[descriptions[i][0]][1] = descriptions[i][1] ;
            if(mp.count(descriptions[i][0]))set.insert(descriptions[i][0]);
        }
        
        for(auto x: mp) {
            // cout<<x.first<<" ->"<<x.second[0]<<", "<<x.second[1]<<endl;
            if(set.count(x.second[0])) set.erase(x.second[0]);
            if(set.count(x.second[1])) set.erase(x.second[1]);
        }
        // for(int i = 0 ; i < set.size(); i++) root = set[i];
        auto it = set.begin();
        root = *it;
        // cout<<"root: "<<root<<endl;

        TreeNode *head = new TreeNode(root);
        queue<TreeNode*> q;
        q.push(head);
        TreeNode* temp;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(!mp.count(temp->val)) continue;
            if(mp[temp->val][0] != -1) {
                temp->left = new TreeNode(mp[temp->val][0]);
                q.push(temp->left);
            } 
            if(mp[temp->val][1] != -1) {
                temp->right = new TreeNode(mp[temp->val][1]);
                q.push(temp->right);
            }        
        }

        return head;
    }
};