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

         int maxh=0;

         int solve(TreeNode *root){
              
              if (root==NULL) return 0;
             
              int lh = solve(root->left);
              int rh = solve(root->right);
              
              maxh =max(maxh,lh+rh);

              return 1+ max(lh,rh);
         }


    int diameterOfBinaryTree(TreeNode* root) {
          
           if (root==NULL) return 0;
            solve(root);
           return maxh;
           

    }
};