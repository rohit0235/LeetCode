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
    TreeNode* solve(int start, int end, int& pidx, 
                    unordered_map<int, int> &mp, vector<int>& postorder) {
           
           if (start>end) return NULL;


            int curr =  postorder[pidx];
           TreeNode* root=new TreeNode(curr);
            pidx--;
          
            int search = mp[curr];

                   if (start==end) return root;
      root->right = solve(search+1,end,pidx ,  mp , postorder);
                    
            root->left = solve(start,search-1,pidx ,  mp , postorder);
      

                    return root;
     }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int p = postorder.size();
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {

            mp[inorder[i]]=i;
        }

        // TreeNode* root = new TreeNode();
        int pidx= p-1;

        return solve(0, n-1, pidx, mp,postorder);
    }
};