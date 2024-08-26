//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    void insertnode(Node* &tail,Node* curr){
         
         tail->next=curr;
         tail=curr;
    }
    Node* segregate(Node* head) {

        // Add code here
        if(head->next == NULL){
            return head;
        }
        
        Node* zerohead=new Node(-1);
        Node* zerotail=zerohead;
        Node* onehead=new Node(-1);
        Node* onetail=onehead;
        Node* twohead=new Node(-1);
        Node* twotail=twohead;
        
        Node* curr=head;
        while(curr != NULL){
            if(curr->data == 0){
                insertnode(zerotail,curr);
            }else if(curr->data == 1){
                insertnode(onetail,curr);
            }else if(curr->data == 2){
                insertnode(twotail,curr);
            }
            curr=curr->next;
        }
        
        if(onehead->next == NULL){
            zerotail->next=twohead->next;
        }else{
            zerotail->next=onehead->next;
        }
        
        onetail->next=twohead->next;
        twotail->next=NULL;
        
        head=zerohead->next;
        delete(zerohead);
        delete(onehead);
        delete(twohead);
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends