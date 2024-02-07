static auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

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
    
    TreeNode* Mapping(TreeNode* root, map<TreeNode*, bool> &visited, map<TreeNode*,TreeNode*> &parent, int start) {

        if(root == NULL) return NULL;

        visited[root] = false;
        TreeNode* ans;
        TreeNode* temp ;        
        queue<TreeNode*> q;

        parent[root] = NULL;
        q.push(root);

        while(!q.empty()) {
            temp = q.front();
            if(temp->val == start) ans = temp;
            q.pop();
            visited[temp] = false;

            if(temp->left) {
                q.push(temp->left);
                parent[temp->left] = temp;
            }

            if(temp->right) {
                q.push(temp->right);
                parent[temp->right] = temp;
            }

        }

        return ans;

    }

    int CalculateTime(TreeNode* root, map<TreeNode*, TreeNode*> &parent, map<TreeNode*,bool> &visited ) {
        
        if(root == NULL) {
            return 0;
        }
        
        visited[root] = true;
        
        int lH = 1;
        int rH = 1;
        int pH = 1;
        
        if(root->left && !visited[root->left]) {
            lH += CalculateTime(root->left, parent, visited);
        }
        
        if(root->right && !visited[root->right]) {
            rH += CalculateTime(root->right, parent, visited);
        }
        
        if(parent[root] != NULL && !visited[parent[root]] ) {
            pH += CalculateTime(parent[root], parent, visited);
        }
        
        return max(max(lH,rH),pH);
    }

    int amountOfTime(TreeNode* root, int start) {
       int time = 0 ;
       map<TreeNode*,TreeNode*> parent;
       map<TreeNode*, bool> visited;
       TreeNode* target;

       target = Mapping(root, visited, parent, start);
       
       time = CalculateTime(target, parent, visited);

       return time - 1;

    }
};