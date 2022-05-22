#include<bits/stdc++.h>
using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;
//     Node(int data) : data(data), next(NULL) {}
// };

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(NULL), right(NULL) {}
};

void BST2SortedLLHelper(TreeNode* treeRoot, vector<TreeNode*> &v) {
    if(!treeRoot) return;
    BST2SortedLLHelper(treeRoot->left, v);
    v.push_back(treeRoot);
    BST2SortedLLHelper(treeRoot->right, v);
}

void BST2SortedLL(TreeNode* &treeRoot)  {
    if(!treeRoot) return;
    vector<TreeNode*> v;
    BST2SortedLLHelper(treeRoot, v);
    for(int i = 0; i < v.size()-1; i++) {
        v[i]->left = NULL;
        v[i]->right = v[i+1];
    }
    treeRoot = v[0];
}

void printTreeLevelWise(TreeNode* t)    {
    if(!t)  return;
    queue<TreeNode*> q;
    q.push(t);
    while(!q.empty()) {
        TreeNode* temp = q.front();
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


TreeNode* takeInputLevelWise()    {
    cout<<"Enter the root: ";
    int rootData;
    cin>>rootData;
    if(rootData == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(rootData);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout<<"Enter left Node of "<<temp->data<<": ";
        int leftChild;
        cin>>leftChild; 
        if(leftChild != -1) {
            TreeNode* leftNode = new TreeNode(leftChild);
            temp->left = leftNode;
            q.push(leftNode);
        }

        cout<<"Enter right Node of "<<temp->data<<": ";
        int rightChild;
        cin>>rightChild;
        if(rightChild != -1) {
            TreeNode* rightNode = new TreeNode(rightChild);
            temp->right = rightNode;            
            q.push(rightNode);
        }
    }
    return root;
}

pair<TreeNode*, TreeNode*> BSTToSortedLL(TreeNode* root)    {
    pair<TreeNode*, TreeNode*> p;
    if(!root) {
        p.first = NULL;
        p.second = NULL;
    }
    else if(!root->left && !root->right) {
        p.first = root;
        p.second = root;
    }
    else if(!root->right) {
        p.first = BSTToSortedLL(root->left).first;
        p.second = root;
        root->left = NULL;
    }
    else if(!root->left) {
        p.first = root;
        p.second = BSTToSortedLL(root->right).second;
    }
    else {
        p.first = BSTToSortedLL(root->left).first;
        p.second = BSTToSortedLL(root->right).second;
        p.second->right = root;
        root->left = NULL;
        root->right = p.first;
    }
    return p;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1

int main()  {
    TreeNode* treeRoot = takeInputLevelWise();
    printTreeLevelWise(treeRoot);
    // Node* root = BST2SortedLL(treeRoot);
    // print(root);
    cout<<endl;
    // BST2SortedLL(treeRoot);
    TreeNode* r = BSTToSortedLL(treeRoot).first;
    printTreeLevelWise(r);
    return 0;
}