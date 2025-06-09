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
    int md=0;
    int height(TreeNode *root){
         
         if (root==NULL) return 0;
         int hl= height(root->left );
         int hr= height(root->right ) ;
          md =max(md, hl+hr);
         return 1+max( hl,hr);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
           
   
         if (root==NULL) return 0;

        height(root);
        return md;
              


    }
};