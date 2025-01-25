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
    
    void inorder(TreeNode* root1,string &s){
        if (root1==NULL) return ;
        if (root1->left==NULL && root1->right==NULL){
             s+=to_string(root1->val)+'_';
             return ;
        }
        inorder(root1->left,s);
        inorder(root1->right,s);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
           
          string s1="";
          string s2="";

          inorder(root1,s1);
          inorder(root2,s2);
          
          return s1==s2;


    }
};