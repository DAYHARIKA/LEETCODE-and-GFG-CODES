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
   void store_dummynodes(Node* head){
      
       Node* temp=head;
       while(temp != NULL){
         
          Node* newnode=new Node(temp->val);
          newnode->next=temp->next;
          temp->next=newnode;
          temp=temp->next->next;

       }

   }
   void connect_randompointers(Node* head){
        
       Node* temp=head;
       while(temp != NULL){

           Node* newnode=temp->next;
           if(temp->random != NULL){
            newnode->random=temp->random->next;
           }
           temp=temp->next->next;

       }
   }
   Node* connect_nextpointers(Node* head){

       Node* dummy=new Node(-1);
       Node* temp1=dummy;
       Node* temp2=head;
       while(temp2 != NULL){

          temp1->next=temp2->next;
          temp2->next=temp1->next->next;
          temp1=temp1->next;
          temp2=temp2->next;
       }
       return dummy->next;
   }
    Node* copyRandomList(Node* head) {
        
        store_dummynodes(head);
        connect_randompointers(head);
        return connect_nextpointers(head);
        
    }
};