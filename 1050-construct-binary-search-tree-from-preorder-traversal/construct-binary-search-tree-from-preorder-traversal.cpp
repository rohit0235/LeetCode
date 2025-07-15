/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int n;

    TreeNode* constructUtil(vector<int>& preorder, int& idx, int mini, int maxi) {

        if (idx >= n)
            return nullptr;

        int key = preorder[idx];
       
        if (key <= mini || key >= maxi)
            return nullptr; 
      TreeNode* root = new TreeNode(key);
      idx++;

       if (idx<n) root->left = constructUtil(preorder, idx, mini, key);
        if (idx<n) root->right = constructUtil(preorder, idx, key, maxi);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
           n = preorder.size();
        // if (n==0) return nullptr;
        // TreeNode *root = new  TreeNode(preorder[0]);

        // solve(root,1, preorder);

        // return root;

        int idx = 0;
        return constructUtil(preorder, idx, INT_MIN, INT_MAX);
    }
};