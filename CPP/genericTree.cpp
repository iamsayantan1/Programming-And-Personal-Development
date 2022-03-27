#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) : data(data) {}
};

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

// template<typename T>
/**
 * It takes input from the user and creates a tree.
 * 
 * @return Nothing.
 */
TreeNode<int>* takeInput()    {
    cout<<"Enter the root: ";
    int data;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    cout << "Enter how many children of "<<data<<": ";
    int n;
    cin >> n;
    for(int i=0; i< n; i++) {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()  {
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* n1 = new TreeNode<int>(2);
    // TreeNode<int>* n2 = new TreeNode<int>(3);
    // TreeNode<int>* n3 = new TreeNode<int>(4);
    // TreeNode<int>* n4 = new TreeNode<int>(5);

    // root->children.push_back(n1);
    // root->children.push_back(n2);
    // n1->children.push_back(n3);
    // n1->children.push_back(n4);
    // root = NULL;
    TreeNode<int>* root = takeInput();
    printTree(root);
    return 0;
}