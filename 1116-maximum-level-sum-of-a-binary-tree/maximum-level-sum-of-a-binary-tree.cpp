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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;

        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int mini =INT_MIN;
        int ans =0;
        while (!q.empty()){
                   
               int n = q.size();
               level++;

               int sum =0;
               for(int i=0;i<n;i++){
                     TreeNode* top= q.front();
                     q.pop();
                    sum+=top->val;
                    if(top->left)q.push(top->left);
                    if(top->right)q.push(top->right);
               }
               if(sum>mini){
                 ans = level;
                 mini = sum;
               }
        }


        return ans;
    }
};