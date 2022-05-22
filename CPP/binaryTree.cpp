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
void levelOrderTraversal(BTNode<T>* t)  {
    if(!t)  return;
    cout<<"Level Order Traversal"<<endl;
    queue<BTNode<T>*> q;
    q.push(t);
    q.push(NULL);
    while(!q.empty())  {
        BTNode<T>* temp = q.front();
        if(!temp) {
            q.pop();
            temp = q.front();
            if(!q.empty())  {
                q.push(NULL);
            }
            cout<<endl;
        }
        q.pop();
        cout<<temp->data<<" ";
        if((temp->left))  {
            q.push(temp->left);
        }
        if((temp->right)) {
            q.push(temp->right);
        }
    }
    cout<<endl;
}

template<typename T>
int countNodes(BTNode<T>* t) {
    if(t == NULL)  return 0;
    int ans = 0;
    return (countNodes(t->left) + countNodes(t->right) + 1);
}

template<typename T>
void inOrder(BTNode<T>* t) {
    if(!t) return;
    inOrder(t->left);
    cout<<t->data<<" ";
    inOrder(t->right);
}

template<typename T>
void preOrder(BTNode<T>* t) {
    if(!t) return;
    cout<<t->data<<" ";
    preOrder(t->left);
    preOrder(t->right);
}

template<typename T>
void postOrder(BTNode<T>* t) {
    if(!t) return;
    postOrder(t->left);
    postOrder(t->right);
    cout<<t->data<<" ";
}

template<typename T>
int maxDepth(BTNode<T>* t) {
    if(!t) return 0;
    return max(maxDepth(t->left), maxDepth(t->right)) + 1;
}

template<typename T>
int countLeafNodes(BTNode<T>* t)  {
    if(!t) return 0;
    if(!t->left && !t->right) return 1;
    return countLeafNodes(t->left) + countLeafNodes(t->right);
}

int maxValue(BTNode<int>* t) {
    if(!t) return 0;
    if(!t->left && !t->right)   return t->data;
    if(!t->left)    return max(maxValue(t->right),t->data);
    if(!t->right)    return max(maxValue(t->left),t->data);
    return max(t->data,max(maxValue(t->left),maxValue(t->right)));
}

int minValue(BTNode<int>* t) {
    if(!t) return 0;
    if(!t->left && !t->right)   return t->data;
    if(!t->left)    return min(minValue(t->right),t->data);
    if(!t->right)    return min(minValue(t->left),t->data);
    return min(t->data,min(minValue(t->left),minValue(t->right)));
}

template<typename T>
bool helperForSymmetric(BTNode<T>* l, BTNode<T>* r) {
    if(!l && r) return false;
    if(l && !r) return false;
    if(!l && !r) return true;
    if(helperForSymmetric(l->left, r->right) && helperForSymmetric(l->right, r->left));
    if(l->data != r->data) return false;
}

template<typename T>
bool isSymmetric(BTNode<T>* t) {
    if(!t) return true;
    return (helperForSymmetric(t->left, t->right));
}

template<typename T>
bool isNodePresent(BTNode<T>* t, T key) {
    if(!t) return false;
    if(key == t->data) return true;
    return (isNodePresent(t->left, key) || isNodePresent(t->right, key));
}

template<typename T>
BTNode<T>* constructTreeFromPreAndIn(T pre[], int s_pre, int e_pre, T in[], int s_in, int e_in) {
    if(s_in>e_in)   return NULL;
    T rootData = pre[s_pre];
    BTNode<T>* root = new BTNode<T>(rootData);

    int rootLocation = -1;
    for(int i=s_in ; i<=e_in; i++)    {
        if(rootData == in[i])
            rootLocation = i;
    }

    root->left = constructTreeFromPreAndIn(pre, s_pre+1, s_pre+(rootLocation-s_in), in, s_in, rootLocation-1);
    root->right = constructTreeFromPreAndIn(pre, s_pre+(rootLocation-s_in)+1, e_pre, in, rootLocation+1, e_in);
    return root;
}

template<typename T>
BTNode<T>* constructTreeFromPostAndIn(T post[], int s_post, int e_post, T in[], int s_in, int e_in) {
    if(s_in>e_in)   return NULL;
    T rootData = post[e_post];
    BTNode<T>* root = new BTNode<T>(rootData);

    int rootLocation = -1;
    for(int i=s_in ; i<=e_in; i++)    {
        if(rootData == in[i])
            rootLocation = i;
    }

    root->left = constructTreeFromPostAndIn(post, s_post, (rootLocation-1 + s_post - s_in), in, s_in, rootLocation-1);
    root->right = constructTreeFromPostAndIn(post, (rootLocation + s_post - s_in), e_post-1, in, rootLocation+1, e_in);
    return root;
}

template<typename T>
int diameterOfBinaryTree(BTNode<T>* t)  {
    if(!t)  return 0;
    if(!t->left && !t->right) return 0;
    return max(maxDepth(t->left)+maxDepth(t->right),max(diameterOfBinaryTree(t->left), diameterOfBinaryTree(t->right)));
}

template<typename T>
pair<int, int> diameterAndHeightOfBinaryTree(BTNode<T>* t) {
    if(!t)  {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    pair<int, int> leftAns = diameterAndHeightOfBinaryTree(t->left);
    pair<int, int> rightAns = diameterAndHeightOfBinaryTree(t->right);

    int diameter = max(leftAns.second + rightAns.second, max(leftAns.first, rightAns.first));
    int height = max(leftAns.second, rightAns.second) + 1;

    pair<int, int> ans;

    ans.first = diameter;
    ans.second = height;

    return  ans;
}

template<typename T>
bool rootToNode(BTNode<T>* t, int key, vector<T> &path)  {
    if(!t)  {
        return false;
    }
    path.push_back(t->data);
    if(t->data == key) {
        return true;
    }
    if(rootToNode(t->left, key, path) || rootToNode(t->right, key, path))   return true;
    path.pop_back();
    return false;
}

// 2 3 4 5 12 -1 10 -1 8 -1 7 -1 -1 9 -1 -1 -1 -1 -1
// 2 3 10 5 4 -1 12 15 -1 -1 -1 13 17 -1 18 -1 -1 -1 -1 -1 -1
// 25 15 50 10 22 35 70 4 12 16 24 31 44 66 90 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()  {
    // BTNode<int>* root = takeInputLevelWise<int>();
    // BTNode<int>* root = new BTNode<int>(1);
    // BTNode<int>* n1 = new BTNode<int>(2);
    // BTNode<int>* n2 = new BTNode<int>(3);
    // BTNode<int>* n3 = new BTNode<int>(4);
    // BTNode<int>* n4 = new BTNode<int>(5);
    // BTNode<int>* n5 = new BTNode<int>(6);
    // BTNode<int>* n6 = new BTNode<int>(7);

    // root->left = n1; 
    // root->right = n2; 
    // n1->left = n3;
    // n1->right = n4;
    // n2->left = n5;
    // n2->right = n6;
    // BTNode<int>* root = takeInput<int>();
    // BTNode<int>* root = takeInputLevelWise<int>();
    // // printTree(root);
    // cout << endl;
    // printTreeLevelWise(root);
    // cout <<endl;
    // // levelOrderTraversal(root);
    // cout <<endl;
    // cout<<"Number of nodes is: "<<countNodes(root)<<endl;
    // cout <<"In-order: ";
    // inOrder(root);
    // cout <<endl;
    // cout<<"Pre-Order: ";
    // preOrder(root);
    // cout <<endl;
    // cout<<"Post-Order: ";
    // postOrder(root);
    // cout <<endl;
    // cout<<"Depth of the tree is: "<<maxDepth(root)<<endl;
    // cout <<endl;
    // cout<<"Maximum value is: "<<maxValue(root)<<endl;
    // cout<<"Minimum value is: "<<minValue(root)<<endl;
    // if(isSymmetric(root))   {
    //     cout<<"Tree is Symmetric."<<endl;
    // }
    // else    {
    //     cout<<"Tree is Asymmetric."<<endl;
    // }
    // int key = 101;
    // if(isNodePresent(root, key)) {
    //     cout<<key<<" is present."<<endl;
    // }
    // else {
    //     cout<<key<<" is not present."<<endl;
    // }

    // int pre[] = {1,2,4,3,5,7,8,6};
    // int in[] = {4,2,1,7,5,8,3,6};

    // BTNode<int>* root = constructTreeFromPreAndIn(pre, 0, 7, in, 0, 7);
    // printTreeLevelWise(root);

    int in[] = {9, 5, 1, 7, 2, 12, 8, 4, 3, 11};
    int post[] = {9, 1, 2, 12, 7, 5, 3, 11, 4, 8};

    BTNode<int>* root = constructTreeFromPostAndIn(post, 0, 9, in, 0, 9);
    printTreeLevelWise(root);
    // cout<<"Diameter of a binary tree is: "<<diameterOfBinaryTree(root)<<" ."<<endl;
    cout<<"Diameter of a binary tree is: "<<diameterAndHeightOfBinaryTree(root).first<<" ."<<endl;
    // cout<<"Height of a binary tree is: "<<maxDepth(root)<<" ."<<endl;
    cout<<"Height of a binary tree is: "<<diameterAndHeightOfBinaryTree(root).second<<" ."<<endl;
    int key = 8;
    vector<int> v;
    bool rn = rootToNode(root, key, v);

    if(rn)  {
        for(int i = 0; i < v.size(); i++)   {
            cout<<v[i]<<" ";
        }
    }
    else cout<<key<<" is not present.";
    cout<<endl;
    printTreeLevelWise(root);
    return 0;
}