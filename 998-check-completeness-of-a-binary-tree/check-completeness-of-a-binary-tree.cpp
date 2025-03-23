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

    int countnodes(TreeNode* root){
          
          if (root==NULL) return 0;

          return 1+countnodes(root->left)+countnodes(root->right);
    }

    bool dfs(TreeNode* root,int i,int total){
          
          if (root==NULL) return true;
          
          if (i>total) return false;

          return dfs(root->left,2*i,total) && dfs(root->right,2*i+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
          
            int total=countnodes(root);
            int i=1;
           return  dfs(root,1,total);


        //    if (root==NULL) return true;
        //    if (root->left==NULL && root->right!=NULL) return false;
        //     //  if (root->left==NULL && root->right==NULL) return true;
        //   return isCompleteTree(root->left) &&  isCompleteTree(root->right); 

    }
};