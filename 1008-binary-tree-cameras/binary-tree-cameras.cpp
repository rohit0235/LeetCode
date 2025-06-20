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

    // int countNodes(TreeNode* root) {
           
    //        if (root==NULL) return 0;

    //        int cl =countNodes(root->left) ;
    //        int cr =countNodes(root->right) ;
            
    //       return cl+cr+1;
    // }

     int camera =0;
    int solve(TreeNode *root){
         
          if (root==NULL) return 1;
           
          int left = solve(root->left);
          int right = solve(root->right);
          if (left==-1  || right==-1) {
                camera++;
                return 0;
          }

          if (left==0 || right==0){
             return 1;
          }

          return -1;
          
           
    }
 
    int minCameraCover(TreeNode* root) {
          
                if (solve(root)==-1) camera++;
                return camera;
         






    }
};