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
    ListNode* reverse(ListNode* head){

        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr != NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         if(l1 == NULL && l2 == NULL){
            return NULL;
         }

         if(l1 != NULL && l2 == NULL){
            return l1;
         }

         if(l1 == NULL && l2 != NULL){
            return l2;
         }
         int carry=0;
         ListNode* temp1=NULL;
         ListNode* temp2=temp1;
         while(l1 != NULL && l2 != NULL){
              int add=carry+l1->val+l2->val;
              int rem=add%10;
              if(temp1== NULL){
                 temp1=new ListNode(rem);
                 temp2=temp1;
              }else{
                 temp2->next=new ListNode(rem);
                 temp2=temp2->next;
              }
            carry=add/10;
            l1=l1->next;
            l2=l2->next;
         }
         while(l1 != NULL){
            int add=carry+l1->val;
            int rem=add%10;
            temp2->next=new ListNode(rem);
            temp2=temp2->next;
            carry=add/10;
            l1=l1->next;
         }

         while(l2 != NULL){
            int add=carry+l2->val;
            int rem=add%10;
            temp2->next=new ListNode(rem);
            temp2=temp2->next;
            carry=add/10;
            l2=l2->next;
         }
         
         if(carry != 0){
            temp2->next=new ListNode(carry);
            temp2=temp2->next;
         }
         //reverse the linkedlist
         //temp1=reverse(temp1);
         return temp1;
    }
};