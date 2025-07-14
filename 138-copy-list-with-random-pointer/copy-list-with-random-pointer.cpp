/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          
            // iinserting a nodee 
           if (head==NULL) return NULL;

            Node *curr= head;

            while (curr){
                         
                      Node *nxt = curr->next;
                      // 1 3  5 6 
                      curr->next = new Node(curr->val);
                      curr=curr->next;
                      curr->next = nxt;
                      curr=curr->next;
                   
            }

            // making random pointers

            curr = head;
            
            while (curr && curr->next){
                 
                      if (curr->random==NULL){
                         curr->next->random = NULL;
                      }
                      else{
                         curr->next->random = curr->random->next;
                      }

                      curr =curr->next->next;
                   
            }


            Node *newhead = head->next;
            Node *newcurr = newhead;

            curr =head;

            while (curr && newcurr){
                  
               curr->next =  curr->next==NULL ? NULL:curr->next->next;
               newcurr->next=  newcurr->next==NULL ? NULL:newcurr->next->next;
               curr=curr->next;
               newcurr=newcurr->next;
                    
            }

            return newhead;





    }
};