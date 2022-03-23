#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL) {}
};

void print(Node* head)   {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* takeTailInput() { 
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)   {
        Node *n = new Node(data);
        if(head == NULL)    {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

int length(Node* head) {
    Node* temp = head;
    if(!temp)
        return 0;
    return length(temp->next)+1;
}

bool search(Node* head, int key)    {
    Node* temp = head;
    while(1)    {
        if(!temp)   {
            return false;
        }
        if(temp->data == key)    {
            return true;
        }
        temp = temp->next;
    }
}

bool search2(Node* head, int key)    {
    
    if(!head)   {
        return false;
    }
    if(head->data == key)    {
        return true;
    }

    return search2(head->next, key);
}

int middle(Node* head) {
    Node* temp = head;
    Node* temp2 = head;
    
    if(!temp)   {
        return -1;
    }
    else    {
        while(1) {
            if(!temp2->next)    {
                return temp->data;
            }
            else if(!temp2->next->next) {
                return temp->next->data;
            }
            temp = temp->next;
            temp2 = temp2 ->next ->next;
        }
    }
}

/**
 * Given a linked list, reverse it in place
 * 
 * @param head The head of the linked list.
 * 
 * @return The head of the reversed linked list.
 */
Node* reverse(Node* head)    {
    
    if(!head)   {
        return NULL;
    }
    else if(!head->next)    {
        return head;
    }
    else    {
        Node* temp = head-> next;
        Node* aft = head-> next -> next;

        head ->next = NULL;
        temp-> next = head;

        while(aft)  {
            head = temp;
            temp = aft;
            aft = aft->next;
            temp -> next = head;
        }
        return temp;
    }
}

Node* deleteFromEnd(Node* head, int loc) {
    Node* temp = head;
    Node* prev = NULL;
    if(!temp)   {
        return NULL;
    }
    else if(loc>=0) {
        Node* temp2 = temp;
        for (size_t i = 0; i < loc; i++)
        {
            if(!temp2->next)  {
                return temp;
            }
            temp2 = temp2 ->next;
        }
        if(!temp2->next)  {
            prev = temp->next;
            delete temp;
            return prev;
        }
        while(temp2->next)  {
            temp2 = temp2 ->next;
            prev = temp;
            temp =temp->next;
        }
    
        prev-> next = temp ->next;
        delete temp;
        return head;
    }
    else    {
        return head;
    }
}

Node* mergedOutput(Node* h1, Node* h2) {
    Node* t1 = h1;
    Node* t2 = h2;
    if(t1 && t2)    {
        Node* head = (t1->data) < (t2->data) ? t1 : t2;
        Node* temp = head;
        if((t1->data) < (t2->data)) {
            t1 = t1->next;
        }
        else    {
            t2 = t2->next;
        }
        while(t1 && t2)   {
            if((t1->data) < (t2->data)) {
                temp -> next = t1;
                t1 = t1->next;
            }
            else    {
                temp -> next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if(t1)   {
            temp -> next = t1;
        }
        if(t2)   {
            temp -> next = t2; 
        }
        return head;
    }
    else if(t1) {
        return t1;
    }
    else if(t2) {
        return t2;
    }
    else    {
        return NULL;
    }

}

Node* mergedOutput2(Node* h1, Node* h2) {
    if(!h1) {
        return h2;
    }
    if (!h2)   {
        return h1;
    }
    
    Node* head = NULL;
    //Node* head = (h1->data) < (h2->data) ? h1 : h2;
    //Node* temp = head;
    int a = h1->data;
    int b = h2->data;
    if((h1->data) < (h2->data)) {
        head = h1;
        head -> next = mergedOutput2((h1->next), h2);
    }
    else    {
        head = h2;
        head -> next = mergedOutput2(h1,(h2->next));
    }
    return head;
}

Node* middleNode(Node* head)  {
    Node* temp = head;
    Node* temp2 = head;
    
    if(!temp)   {
        return NULL;
    }
    else    {
        while(1) {
            if(!temp2->next)    {
                return temp;
            }
            else if(!temp2->next->next) {
                return temp;
            }
            temp = temp->next;
            temp2 = temp2 ->next ->next;
        }
    }
}

/**
 * Given a linked list, split it into two halves, sort each half, and merge the two sorted halves
 * 
 * @param head The head of the linked list.
 * 
 * @return The head of the sorted linked list.
 */
Node* mergeSort(Node* head) {
    if(!head || !head -> next) {
        return head;
    }
    Node* h1 = head;
    Node* mid =  middleNode(h1);
    Node* h2 = mid->next;
    mid-> next = NULL;
    Node* t1 = mergeSort(h1);
    Node* t2 = mergeSort(h2);
    return mergedOutput(t1, t2);
}

Node* takeCircularTailInput() { 
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)   {
        Node *n = new Node(data);
        if(head == NULL)    {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    if(head)    {
        tail->next = head;
    }
    return head;
}

void circularPrint(Node* head)   {
    if(head)    {
        Node* temp = head->next;
        cout<<head->data;
        while(temp != head) {
        cout<<" -> "<<temp->data;
        temp = temp->next;
        }
    }
    cout<<endl;
}

int main()  {
    // Node* h1 = takeTailInput();
    // print(h1);
    // Node* h2 = takeTailInput();
    // print(h2);
    // cout<<"Merged Output"<<endl;
    // cout << endl;
    // Node* head = mergedOutput(h1, h2);
    // print(head);
    // cout << endl;
    // Node* head2 = mergedOutput2(h1, h2);
    // print(head2);
    // cout<<length(head)<<endl;
    // int element = 3;
    // if(search2(head, element)) {
    //     cout<<element<<" is present."<< endl;
    // }
    // else    {
    //     cout << element <<" is not present."<< endl;
    // }
    // cout<<"Middle = " << middle(head)<<endl;
    // print(reverse(head));
    // Node* ll = deleteFromEnd(head, 2);
    // print(ll);
    // cout<<middleNode(h1)->data<<endl;
    // Node* head = mergeSort(h1);
    // print(head);

    Node* h1 = takeCircularTailInput();
    circularPrint(h1);

    return 0;
}