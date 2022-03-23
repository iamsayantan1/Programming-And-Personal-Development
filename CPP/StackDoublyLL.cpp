#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T data) : data(data), next(NULL), prev(NULL) {}    
};

template<typename T>
class Stack {
    Node<T>* head;
    Node<T>* tail;
    Node<T>* temp;
    int length;

public:
    Stack() : head(NULL), tail(NULL), temp(NULL), length(0) {}

    void push(T data) {
        if(!head)   {
            Node<T>* newNode = new Node<T>(data);
            newNode->data = data;
            head = newNode;
            tail = head;
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            tail->next = newNode;
            temp = tail;
            tail = tail->next;
            tail->prev = temp;
        }
        length++;
    }

    void pop() {
        if(!head) {
            cout <<"Stack is empty!" << endl;
        }
        else if(!head->next)    {
            head = NULL;
            length--;
        }
        else   {
            temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = NULL;
            length--;
        }
    }

    T top() {
        if(head)    {
            return tail->data;
        }
        else    {
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
    }

    bool isEmpty()  {
        if(!head)   {
            return true;
        }
        else    {
            return false;
        }
    }

    int size() {
        return length;
    }
};

int main()  {
    Stack<int> s;
    s.push(1);
    s.push(3);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(12);
    cout << s.top() << endl;
    cout <<s.size()<<endl;
    return 0;
}