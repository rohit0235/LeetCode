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
    ListNode* swapNodes(ListNode* head, int k) {

        if (head == NULL)
            return NULL;

        // 1 2 3 4 5
        //  t1 =2  t2=3
        // t1->next /

             ListNode *temp=head;
             ListNode* data1=head;
             ListNode* data2=head;
             int count=1;
             while (temp){
                  count++;
                  temp=temp->next;
             }

            
             int check=1;
             while (data1){ 
                  if (check==k) break;
                

                  check++;
                  data1=data1->next;
                 
             
             }
        
            check=1;
             while (data2){ 
                //   if (check==k) data1=temp;
                  if (check==count-k) break;

                  check++;
                  data2=data2->next;
                 
             
             }
            //  cout<<data1<<" "<<data2<<endl;

             swap(data1->val,data2->val);

             return head;



    }
};