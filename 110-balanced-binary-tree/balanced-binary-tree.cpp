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
   
    int hei(TreeNode *root){
          if (root==NULL) return 0;

          int lefth =hei(root->left);
          if (lefth==-1) return -1;
          int righth =hei(root->right);
          if (righth==-1) return -1;

          if (abs(lefth-righth)>1){
             return -1;
          }


          return  max(hei(root->left),hei(root->right))+1 ;
    }
    
    bool isBalanced(TreeNode* root) {
               if (root==NULL) return true;
                
               return hei(root)!=-1;
    }
};