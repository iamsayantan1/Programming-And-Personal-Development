#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

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

Node* takeHeadInput() {
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)   {
        Node *n = new Node(data);
        if(tail == NULL)    {
            head = n;
            tail = n;
        }
        else    {
            n->next = head;
            head = n;
        }
        cin>>data;
    }
    return head;
}

// Node* reverse(Node *h)  {
//     Node* head = h;
//     Node* temp = NULL;
//     Node* temp2 = head;
//     while(temp2 != NULL)   {
//         if(temp == NULL) {
//             temp = head->next;
//             temp2 = temp->next;
//             head->next = NULL;
//             temp->next = head;
//             head = temp;
//         }
//         else    {
//             temp = temp2;
//             temp2 = temp->next;
//             temp->next = head;
//             head = temp;
//         }
//     }
//     return head;
// }

void length(Node* head)  {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    cout<<"Length of the LinkedList is: "<<length<<" ."<<endl;
}

int length2(Node* head)  {
    int length = 0;
    Node* temp = head;
    while(temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* reverse(Node *h)  {
    Node* head = h;
    
    if(!head || !head->next) {
        return head;
    }
    Node* temp = head -> next;
    Node* temp2 = temp -> next;
    head -> next = NULL;
    temp -> next = head;
    head = temp;
    while(temp2)    {
        temp = temp2;
        temp2 = temp2->next;
        temp -> next = head;
        head = temp;
    }
    return head;
}

void ithElement(Node* head, int pos)  {
    Node* temp = head;
    // int len = length2(temp);
    int count = 0;

    while(pos>0 && temp && count != pos)   {
        temp = temp->next;
        count++;
    }

    if(pos<0 || !temp)  {
        cout<<pos<<" th element is not present."<<endl;
    }
    else    {
        cout<<pos<<" th element is: "<<temp->data<<endl;
    }

    // if(pos>=0 && pos < len)    {
    //     for(int i=1; i<=pos; i++) {
    //         temp = temp->next;
    //     }
    //     cout<<pos<<" th element is: "<<temp->data<<endl;
    // }
    // else    {
    //     cout<<pos<<" th element is not present."<<endl;
    // }
}

int ithElement2(Node* head, int pos)  {
    Node* temp = head;
    int len = length2(temp);
    
    for (size_t i = 1; i <= pos; i++)
    {
        if(pos<0 || pos>=len) {
            return -1;
        }
        temp = temp->next;
    }
     return temp->data;
}

void insertElement(Node* &head, int pos, int value)   {
    Node* temp = head;
    Node* prev = NULL;
    Node* n = new Node(value);
    int count = 0;

    while(pos>0 && temp && count != pos)   {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if(pos<0 || (!temp && count!=pos))  {
        cout<<pos<<" th position is not present."<<endl;
    }
    else    {
        if(!prev)   {
            prev = head;
            head = n;
            head ->next = prev;
        }
        else    {
            prev -> next = n;
            n -> next = temp;
        // cout<<pos<<" th element is: "<<temp->data<<endl;
        }
    }
}

// void deleteElement(Node* head, int loc)   {
//     Node* temp = head;
//     Node* prev = NULL;
//     int e = 0;
//     if(!temp)   {
//         cout<<"Nothing is present."<< endl;
//     }
//     else    {
//         while((e!= loc) && (temp->next) && loc > 0) {
//             prev = temp;
//             temp=temp->next;
//             e++;
//         }
//         if(e==loc)  {
//             Node* temp2 = temp->next;
//             prev->next = temp2;
//             delete temp;
//         }
//         else    {
//             cout<<loc<<" th element is not present."<< endl;
//         }
//     }
// }

void deleteElement(Node* &head, int pos)   {
    Node* temp = head;
    Node* prev = NULL;
    int count = 1;

    if(pos == 0 && temp != NULL)    {
        head = temp->next;
        delete temp;
    }

    while(pos>0 && temp && count <= pos)   {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if(pos == count)    {
        prev -> next = temp -> next;
        delete temp;
    }
    else    {
        cout <<"Location is not present."<< endl;
    }
}

int main()  {
    // Node *n1 = new Node(1);
    // Node *n2 = new Node(2);
    // Node *n3 = new Node(3);
    // Node *n4 = new Node(4);
    // Node *n5 = new Node(5);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;

    // print(n1);

    // Node* head = takeTailInput();
    // print(head);

    Node* head = takeHeadInput();
    print(head);


    cout<<4<<" th Element: "<<ithElement2(head, 4)<<endl;

    head = reverse(head);
    print(head);
    length(head);
    ithElement(head, 4);
    insertElement(head, -1, 40);
    print(head);
    deleteElement(head, 0);
    print(head);
    return 0;
}