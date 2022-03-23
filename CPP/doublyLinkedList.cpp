#include<iostream>
using namespace std;

class doublyNode {
public:
    int data;
    doublyNode* prev;
    doublyNode* next;

    doublyNode(int data) : data(data), prev(NULL), next(NULL) {}
};

void doublyPrintForward(doublyNode* head)   {
    doublyNode* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void doublyPrintBackward(doublyNode* tail)   {
    cout<<"NULL";
    doublyNode* temp = tail;
    while(temp != NULL) {
        cout<<" <- "<<temp->data;
        temp = temp->prev;
    }
    cout<<endl;
}

doublyNode* doublyTakeTailInput(bool headOrTail) { 
    int data;
    cin>>data;
    doublyNode* head = NULL;
    doublyNode* tailNext = NULL;
    doublyNode* tailPrev = NULL;
    while(data != -1)   {
        doublyNode *n = new doublyNode(data);
        if(head == NULL)    {
            head = n;
            tailNext = n;
        }
        else {
            tailPrev = tailNext;
            tailPrev->next = n;
            tailNext = n;
            tailNext->prev = tailPrev; 
        }
        cin>>data;
    }
    if(headOrTail)
        return head;
    else
        return tailNext;
}

doublyNode* CircularDoublyTakeTailInput(bool headOrTail) { 
    int data;
    cin>>data;
    doublyNode* head = NULL;
    doublyNode* tailNext = NULL;
    doublyNode* tailPrev = NULL;
    while(data != -1)   {
        doublyNode *n = new doublyNode(data);
        if(head == NULL)    {
            head = n;
            tailNext = n;
        }
        else {
            tailPrev = tailNext;
            tailPrev->next = n;
            tailNext = n;
            tailNext->prev = tailPrev; 
        }
        cin>>data;
    }
    if(head)    {
        tailNext->next = head;
        head->prev = tailNext;
    }
    if(headOrTail)
        return head;
    else
        return tailNext;
}

/**
 * Prints the data of the nodes in a doubly linked list in a forward direction
 * 
 * @param head The head of the doubly linked list.
 */
void CircularDoublyPrintForward(doublyNode* head)   {
    if(head) {
        doublyNode* temp = head-> next;
        cout<<head->data;
        while(temp != head) {
            cout<<" -> "<<temp->data;
            temp = temp->next;
        }
    }
    cout<<endl;
}

/**
 * Prints the data of the nodes in the doubly linked list in the reverse order
 * 
 * @param head The head of the doubly linked list.
 */
void CircularDoublyPrintBackward(doublyNode* head)   {
    if(head) {
        doublyNode* temp = head-> prev;
        while(temp != head) {
            cout<<temp->data<<" <- ";
            temp = temp->prev;
        }
        cout<<head->data;
    }
    cout<<endl;
}

int main()  {
    // doublyNode* head = doublyTakeTailInput(true);
    // doublyPrintForward(head);
    // doublyNode* tail = doublyTakeTailInput(false);
    // doublyPrintBackward(tail);
    doublyNode* h = CircularDoublyTakeTailInput(true);
    CircularDoublyPrintForward(h);
    CircularDoublyPrintBackward(h);

    // cout<<tail->data<<"  "<<tail->prev->data<<"  "<<tail->prev->prev->data<<endl;
    // doublyNode* temp = head -> next -> next;
    // cout<<temp->data<<"  "<<temp->prev->data<<"  "<<temp->prev->prev->data<<endl;
    return 0;
}