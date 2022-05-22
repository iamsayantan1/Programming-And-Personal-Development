#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode {
public:
    T data;
    BTNode* left;
    BTNode* right;
    BTNode(T data) : data(data), left(NULL), right(NULL)   {}
    ~BTNode()   {
        delete left;
        delete right;
    }
};

template<typename T>
void printTreeLevelWise(BTNode<T>* t)    {
    if(!t)  return;
    queue<BTNode<T>*> q;
    q.push(t);
    while(!q.empty()) {
        BTNode<T>* temp = q.front();
        q.pop();
        cout<<temp->data<<": ";
        if((temp->left)) {
            cout<<"L= "<<temp->left->data<<" ";
            q.push(temp->left);
        }
        if((temp->right)) {
            cout<<"R= "<<temp->right->data<<" ";
            q.push(temp->right);
        }
        cout<<endl;
    }
}

template<typename T>
void printTree(BTNode<T>* t)   {
    if(t == NULL) return;
    cout<<t->data<<": ";
    if(t->left) cout<<"L= "<<t->left->data<<", ";
    if(t->right) cout<<"R= "<<t->right->data<<" ";
    cout<<endl;
    printTree(t->left);
    printTree(t->right);
}

template<typename T>
BTNode<T>* takeInput()   {
    // if(t == NULL) return;
    T rootData;
    cout<<"Enter data: ";
    cin>>rootData;

    if(rootData == -1)  {
        return NULL;
    }

    BTNode<T>* root = new BTNode<T>(rootData);
    root->left = takeInput<T>();
    root->right = takeInput<T>();
    return root;
}

template<typename T>
BTNode<T>* takeInputLevelWise()    {
    cout<<"Enter the root: ";
    T rootData;
    cin>>rootData;
    if(rootData == -1) {
        return NULL;
    }
    BTNode<T>* root = new BTNode<T>(rootData);
    queue<BTNode<T>*> q;
    q.push(root);
    while(!q.empty()) {
        BTNode<T>* temp = q.front();
        q.pop();

        cout<<"Enter left Node of "<<temp->data<<": ";
        T leftChild;
        cin>>leftChild; 
        if(leftChild != -1) {
            BTNode<T>* leftNode = new BTNode<T>(leftChild);
            temp->left = leftNode;
            q.push(leftNode);
        }

        cout<<"Enter right Node of "<<temp->data<<": ";
        T rightChild;
        cin>>rightChild;
        if(rightChild != -1) {
            BTNode<T>* rightNode = new BTNode<T>(rightChild);
            temp->right = rightNode;            
            q.push(rightNode);
        }
    }
    return root;
}

template<typename T>
BTNode<T>* searchinBST(BTNode<T>* t, T value) {
    if(!t) return NULL;
/* Checking if the value is present in the tree or not. Recursive Method */
    // if(value == t->data) return t;
    // if(value < t->data) {
    //     return searchinBST(t->left, value);
    // }
    // if(value > t->data) {
    //     return searchinBST(t->right, value);
    // }
/* ------------------------------------------------------------------- */



/* Checking if the value is present in the tree or not. Iterative Method */
    while(t)   {
        if(value == t->data) return t;
        else if(value<t->data) {
            t = t->left;
        }
        else    {
            t = t->right;
        }
    }
    return NULL;
/* ------------------------------------------------------------------- */
}

int minValueInBST(BTNode<int>* t)   {
    if(!t)  return -1;
    while(t->left) {
        t = t->left;
    }
    return t->data;
}

int maxValueInBST(BTNode<int>* t)   {
    if(!t)  return -1;
    while(t->right) {
        t = t->right;
    }
    return t->data;
}

int rangeSum(BTNode<int>* t, int s, int e)  {
    if(!t || s>e)  return 0;
    int sum = 0;

    if(s<=t->data && e>=t->data)  {
        sum += t->data + rangeSum(t->left, s, e) + rangeSum(t->right, s, e);
    }
    if(s > t->data)   {
        sum += rangeSum(t->right, s, e);
    }
    if(e < t->data) {
        sum += rangeSum(t->left, s, e);
    }
    return sum;
}

bool isBSTHelper(BTNode<int>* t, int s, int e)   {
    if(t->data > s && t->data < e)  {
        if(isBSTHelper(t->left, s, t->data) && isBSTHelper(t->right, t->data, e))   {
            return true;
        }
    }
    else    return false;
}

bool isBST(BTNode<int>* t) {
    if(!t) return false;
    return isBSTHelper(t,INT_MIN, INT_MAX);
}

BTNode<int>* balancedBST(vector<int> v,int s, int e) {
    if(s>e) return NULL;
    int mid = (s + e) / 2;
    int roootData = v[mid];
    BTNode<int>* root = new BTNode<int>(roootData);
    root->left = balancedBST(v, s, mid-1);
    root->right = balancedBST(v, mid+1, e);
    return root;
}

// 2 3 4 5 12 -1 10 -1 8 -1 7 -1 -1 9 -1 -1 -1 -1 -1
// 2 3 10 5 4 -1 12 15 -1 -1 -1 13 17 -1 18 -1 -1 -1 -1 -1 -1
// 25 15 50 10 22 35 70 4 12 16 24 31 44 66 90 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1

int main() {
    // BTNode<int>* root = takeInputLevelWise<int>();
    // int key = 30;
    // cout<<endl;
    // BTNode<int>* searchNode = searchinBST(root, key);
    // if(searchNode) {
    //     cout<<key<<" is present."<<endl;
    // }
    // else    {
    //     cout <<key<<" is not present."<< endl;
    // }
    // cout<<searchNode->data<<endl;

    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    BTNode<int>* root = balancedBST(v,0,v.size()-1);

    printTreeLevelWise(root);

    // cout<<"Minimum value is: "<<minValueInBST(root)<<endl;
    // int sv = 15;
    // int ev = 35;
    // cout<<"Sum of the values between "<<sv<<" and "<<ev<<" is: "<<rangeSum(root, sv, ev)<<endl;
    // if(isBST(root)) {
    //     cout<<"Binary Search Tree."<<endl;
    // }
    // else    {
    //     cout<<"Not a Binary Search Tree."<<endl;
    // }
    return 0;
}