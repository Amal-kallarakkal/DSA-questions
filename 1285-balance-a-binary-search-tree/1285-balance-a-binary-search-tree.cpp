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

    void traverse(TreeNode* root, vector<int> &nums) {
        if(!root) return;

        if(root->left) traverse(root->left, nums);

        nums.push_back(root->val);

        if(root->right) traverse(root->right, nums);
    }

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(q.empty() && temp) q.push(NULL);
            if(temp == NULL) {
                cout<<endl;
                continue;
            }   
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
    }

    TreeNode* solve(vector<int> &nums, TreeNode* root, int i, int j) {

        if(i >= j) return NULL;
        int mid = (i+j)/2;
        
        TreeNode* root2 = new TreeNode(nums[mid]);

        root2->left = solve(nums, root2->left,i, mid);

        root2->right = solve(nums, root2->right, mid +1, j);

        return root2;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;

        traverse(root, nums);
        int n = nums.size();
        // int nums[n] ;
        // for(int i = 0; i < n; i ++) nums[i] = nums[i];
        TreeNode* root2 = solve(nums, root, 0, n);
        vector<int> nums2;
        traverse(root2, nums2);
        // for(auto x: nums2)cout<<x<<" ";'
        bfs(root2);
        return root2;
    }
};