//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node *down,Node *right){
        
        Node* dummyNode=new Node(-1);
        Node*  curr=dummyNode;
        Node *t1=down;
        Node *t2=right;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->data < t2->data)
            {
                curr->bottom=t1;
                curr=curr->bottom;
                t1=t1->bottom;
            }
            else
            {
                curr->bottom=t2;
                curr=curr->bottom;
                t2=t2->bottom;
            }
        }
        if(t1)
        {
            curr->bottom=t1;
        }
        if(t2)
        {
            curr->bottom=t2;
        }
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
       Node* temp=root;
        if(temp==NULL||temp->next==NULL)
        {
            return temp;
        }
        
        Node* mergedHead=flatten(temp->next);
        temp->next=NULL;
        return merge(root,mergedHead);
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends