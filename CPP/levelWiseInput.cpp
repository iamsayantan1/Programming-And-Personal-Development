#include<bits/stdc++.h>
using namespace std;

/* A template class. */
template<typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) : data(data) {}
    ~TreeNode() {
        for(int i=0; i<children.size(); i++)    {
            delete children[i];
        }
    }
};


/* A recursive function. */
template<typename T>
void printTree(TreeNode<T>* t)   {
    if(t==NULL) return;
    cout<<t->data<<": ";
    for(int i=0; i<t->children.size();i++)  {
        cout<<t->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0; i<t->children.size();i++)  {
        printTree(t->children[i]);
    }
}



/* A recursive function that prints the tree level wise. */
template<typename T>
void printTreeLevelWise(TreeNode<T>* t)   {
    if(t==NULL) return;
    queue<TreeNode<int>*> q;
    q.push(t);
    while(!q.empty())   {
        cout<<q.front()->data<<": ";
        for(int i=0; i<q.front()->children.size();i++)  {
            cout<<q.front()->children[i]->data<<" ";
            q.push(q.front()->children[i]);
        }
        cout<<endl;
        q.pop();
    }
}




/**
 * It takes input from the user and creates a tree.
 * 
 * @return Nothing.
 */
template<typename T>
TreeNode<T>* takeInput()    {
    cout<<"Enter the root: ";
    T data;
    cin>>data;
    TreeNode<T>* root = new TreeNode<T>(data);
    cout << "Enter how many children of "<<data<<": ";
    int n;
    cin >> n;
    for(int i=0; i< n; i++) {
        TreeNode<T>* child = takeInput<T>();
        root->children.push_back(child);
    }
    return root;
}



template<typename T>
TreeNode<T>* takeInputLevelWise() {
    queue<TreeNode<T>*> q;
    T rootData;
    cout<<"Enter the root: "<<endl;
    cin>>rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    q.push(root);

    int n;
    
    while(!q.empty())   {
        TreeNode<T>* temp = q.front();
        q.pop();
        cout<<"Enter the number of children of "<<temp->data<<": "<<endl;
        cin>>n;
        if(n!=0)  {
            cout <<"Enter the children of "<<temp->data<<": "<<endl;
        }
        for(int i=0; i<n; i++)  {
            T childData;
            cin>>childData;
            TreeNode<T>* child = new TreeNode<T>(childData);
            q.push(child);
            temp->children.push_back(child);
        }
    }
    return root;
}

template<typename T>
int countNodes(TreeNode<T>* t)   {
    if(t==NULL) return 0;
    int ans = 1;
    for(int i=0; i<t->children.size();i++)  {
        ans += countNodes(t->children[i]);
    }
    return ans;
}

template<typename T>
int height(TreeNode<T>* t)   {
    if(t==NULL) return 0;
    int ans = 0;
    for(int i=0; i<t->children.size();i++)  {
        // ans = height(t->children[i])>max ? height(t->children[i]) : max;
        ans = max(ans, height(t->children[i]));
    }
    return 1+ans;
}

template<typename T>
void printNodesAtLevelK(TreeNode<T>* t, int k)   {
    if(t==NULL) return;
    if(k==0) {
        cout<<t->data<<" ";
        return;
    }
    for(int i=0; i<t->children.size();i++)  {
        printNodesAtLevelK(t->children[i],k-1);
    }
}

template<typename T>
int countLeafNodes(TreeNode<T>* t)   {
    if(t==NULL) return 0;
    int ans = 0;
    if(t->children.empty()) {
        return 1;
    }
    for(int i=0; i<t->children.size();i++)  {
        ans += countLeafNodes(t->children[i]);
    }
    return ans;
}

template<typename T>
void preOrderTraversal(TreeNode<T>* t)    {
    if(!t)  return;
    cout<<t->data<<" ";
    for(int i=0;i<t->children.size();i++)   {
        preOrderTraversal(t->children[i]);
    }
}

template<typename T>
void postOrderTraversal(TreeNode<T>* t)    {
    if(!t)  return;
    for(int i=0;i<t->children.size();i++)   {
        postOrderTraversal(t->children[i]);
    }
    cout<<t->data<<" ";
}

template<typename T>
void deleteTree(TreeNode<T>* t)    {
    if(!t)  return;
    for(int i=0;i<t->children.size();i++)   {
        deleteTree(t->children[i]);
    }
    delete t;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
// 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
int main()  {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout<<endl;
    printTreeLevelWise(root);
    // printTree(root);
    cout <<"Number of node is: "<<countNodes(root)<<endl;
    cout <<"Height of the tree is: "<<height(root)<<endl;
    printNodesAtLevelK(root, 2);
    cout <<endl;
    cout<<"Number of leaf node is: "<<countLeafNodes(root)<<endl;
    printTree(root);
    cout<<"Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout <<endl;
    cout<<"Post-Order Traversal: ";
    postOrderTraversal(root);
    // deleteTree(root);
    delete root;
    return 0;
}