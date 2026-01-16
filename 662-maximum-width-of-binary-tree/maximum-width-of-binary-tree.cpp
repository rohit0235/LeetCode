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
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long maxi = 0;
        while (!q.empty()) {

            long long n = q.size();
            long long l = q.front().second;
            long long r = q.back().second;
            // cout<<l<<" "<<r<<endl;
             maxi = max(maxi, r-l+1);
            for (long long i = 0; i < n; i++) {
                TreeNode* front = q.front().first;
                long long val = q.front().second;
              
                q.pop();
                if (front->left)
                    q.push({front->left, 2 * val + 1});
                if (front->right)
                    q.push({front->right, 2 * val+2});
            }
        }
        return maxi;

        // int mini = INT_MAX;
        // int maxi = -1;

        // while (!q.empty()) {
        //     TreeNode* front = q.front().first;
        //     int val = q.front().second;
        //       q.pop();
        //       cout<<val<<endl;
        //     maxi = max(maxi, val);
        //     mini = min(mini, val);
        // }

        // if(maxi==mini) return 1;

        // return maxi-mini;
    }
};