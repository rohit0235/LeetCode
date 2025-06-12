/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

                    stack<ListNode*>st;
                    int l=1;
                    ListNode *curr = head;
                    while (curr){
                    
                         st.push(curr);
                         curr=curr->next;
                    }


                    curr=head;
                    int k =st.size()/2;
                    while (k--){
                             
                             ListNode *temp =curr->next ;
                             ListNode *topn = st.top();
                             st.pop();
                             curr->next =topn;
                             topn->next=temp;
                             curr=temp;
                            //  k--;
                             


                    }
                  curr->next =NULL;

        

    }
};