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

int h(TreeNode *root){
       if(!root) return 0;
      int lefth = h(root->left);
         int righth = h(root->right);
  if(lefth==-1 || righth==-1) return -1;
    if(abs(lefth-righth)>1) return -1;
 

       return  max(lefth,righth)+1;
}
    bool isBalanced(TreeNode* root) {
         
         if(!root) return 1;
        if(h(root)==-1) return false;
        return 1;
    }
};