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
    int total = 0;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        // cout << root->val << endl;
        // int sum = root->val;
        // if (root->left)
        //     sum += root->left->val;
        // if (root->right)
        //     sum += root->right->val;
        // solve(root->left);
        // solve(root->right);

        return root->val + solve(root->left) + solve(root->right);
    }
      const int mod = 1e9+7;
    long long maxi = 0;

    long long  solve2(TreeNode *root){
          
          if (!root) return 0;

          long long currsum = root->val + solve2(root->left)+solve2(root->right);
          long long remsum = currsum*(total-currsum);
          maxi = max(maxi , remsum);
          return currsum;

    }

    int maxProduct(TreeNode* root) {
        if (root == NULL)
            return 0;

        total = solve(root);
        solve2(root);
        return maxi%mod;
    }
};