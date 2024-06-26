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
#pragma GCC optimize("OFast")
class Solution {
public:
    // ios::sync_with_stdio(0)
    void traverse(TreeNode* root, vector<int> &nums) {
        if(!root) return;

        if(root->left) traverse(root->left, nums);

        nums.push_back(root->val);

        if(root->right) traverse(root->right, nums);
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
        
        return solve(nums, root, 0, n);
    }
};