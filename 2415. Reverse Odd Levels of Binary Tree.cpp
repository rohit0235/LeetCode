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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
           if (root==NULL) return root;
           
           queue<TreeNode*>q;
           q.push(root);
         
           int level =0;
 
           while (!q.empty()){
                   int n =q.size();
               vector<TreeNode*>levelnode;

               for (int i=0;i<n;i++){

                      TreeNode *curr=q.front();
                      levelnode.push_back(curr);
                      q.pop();

                      if (curr->left) q.push(curr->left);
                      if (curr->right) q.push(curr->right);
               }
               
               if (level &1 ){
                    
                    int k=levelnode.size();
                    for (int i=0;i<k/2;i++){

                        swap(levelnode[i]->val , levelnode[n-i-1]->val);
                    }

               }
               level++;
           }
     return root;

    }
  
};
