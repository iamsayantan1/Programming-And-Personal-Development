#include<bits/stdc++.h>
using namespace std;

// class linkedList
// {
// private:
//     /* data */
// public:
//     linkedList(/* args */);
//     ~linkedList();
// };

// linkedList::linkedList(/* args */)
// {
// }

// linkedList::~linkedList()
// {
// }

class Node {
public:
    int data;
    Node *next;

    Node(int data)  {
        this -> data = data;
        next = NULL;
    }
};

void print(Node *&temp)  {
    while(temp!= NULL)   {
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout <<"NULL"<< endl;
}

// void print(Node *&h)  {
//     Node *temp = h;
//     while(temp!= NULL)   {
//         cout << temp->data<<"->";
//         temp = temp->next;
//     }
//     cout <<"NULL"<< endl;
// }

int main()  {
    cout<<"LinkedList"<<endl;
    Node a(100);
    Node b(200);
    Node c(300);
    Node d(400);
    Node e(500);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    Node *head = &a;
    
    //cout<<a.data<<" "<<b.data<<endl;
    //cout<<(head->data)<<" "<<(head->next->data)<<endl;

    print(head);

    //cout<<endl;

    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    
    Node *h = n1; 

    print(h);
    print(h);

    return 0;
}