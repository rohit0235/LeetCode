/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), _next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            Node* prev = NULL; // Keep track of the previous node in the current level

            for (int i = 0; i < level_size; ++i) {
                Node* current = q.front();
                q.pop();

                // If prev is not NULL, it means current is not the first node of this level
                // So, connect prev's next to current
                if (prev != NULL) {
                    prev->next = current;
                }
                
                // Update prev to be the current node for the next iteration
                prev = current;

                // Enqueue children for the next level
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
     
     
        }

        return root; // Return the original root, which now has connected next pointers
    }
};