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
    
    int minimumOperations(TreeNode* root) {
        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0, n, small;
        TreeNode* temp;
        while(!q.empty()) {
            n = q.size();
            for(int i = 0; i < n; i++) {
                temp = q.front();
                nums.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            for(int i = 0 ; i < n; i++) {
                small = i;
                for(int j = i + 1; j < n; j++) {
                    if(nums[j] < nums[small]) small = j;
                }
                if(i != small) {
                    cnt++;
                    swap(nums[i], nums[small]);
                }
            }
            nums.clear();
        }
       
        return cnt;
    }
};