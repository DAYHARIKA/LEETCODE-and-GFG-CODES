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
    void solve(ListNode* &head,ListNode* ptr,ListNode* prev,ListNode* next){
        
              
            if(ptr == NULL){
                head=prev;
                return;
            }
            next=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=next;  
            solve(head,ptr,prev,next);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* ptr=head;
        ListNode* prev=NULL;
        ListNode* next;
        solve(head,ptr,prev,next);
        return head;     
    }
};