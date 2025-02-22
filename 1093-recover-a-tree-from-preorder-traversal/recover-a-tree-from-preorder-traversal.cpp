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
class Solution
{
public:
    static TreeNode* recoverFromPreorder(string_view tvsl)
    {
        int val {};
        size_t depth {};
        TreeNode* dummy = new TreeNode();
        stack<TreeNode*> stk {{ dummy }};

        for (auto it { tvsl.begin() }; it != tvsl.end(); ++it)
        {
            if (*it == '-')
                ++depth;
            else
            {
                val = 10 * val + (*it - '0');
                if ((it + 1) != tvsl.end() && *(it + 1) != '-') continue;

                while (stk.size() > depth + 1) stk.pop();
                TreeNode* prnt = stk.top();
                TreeNode* node = new TreeNode(val);
                if (prnt->left)
                    prnt->right = node;
                else
                    prnt->left  = node;
                stk.push(node);
                depth = 0;
                val = 0;
            }
        }

        TreeNode* ans { dummy->left };
        delete dummy;
        return ans;
    }
};