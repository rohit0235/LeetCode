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
     int ans =0;

     void solve(TreeNode *root, int maxi){
         if(root==NULL) return ;

         if(root->val>=maxi) ans++;

         solve(root->left, max(root->val , maxi));
         solve(root->right, max(root->val , maxi));
     }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        solve(root, INT_MIN);

        return ans;
    }
};