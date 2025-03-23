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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int& index){

        if (start>end) return NULL;

        int rootval=preorder[index];

        int i=start;
        for(;i<=end;i++){
                   if (inorder[i]==rootval){
                       break;
                   }  
        }          
         
        index++;

        TreeNode *root=new TreeNode(rootval);
        root->left= solve(preorder,inorder,start,i-1,index);
        root->right= solve(preorder,inorder,i+1,end,index);

        return root;
     



    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          
              int index=0;
             int n=preorder.size();
            return  solve(preorder,inorder,0,n-1,index);


           
    }
};