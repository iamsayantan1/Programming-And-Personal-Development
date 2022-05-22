#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(NULL), right(NULL) {}

    ~TreeNode() {
        delete left; 
        delete right;
    }
};

class BST {
    TreeNode* root;
public:
    BST() : root(NULL) {}
    ~BST() {
        delete root;
        // delete root->left;
        // delete root->right;
    }

    void deleteN() {
        delete root;
    }

    void insert(int nodeData)   {
        TreeNode* node = new TreeNode(nodeData);
        if(!root) root = node;
        else    {
            TreeNode* temp = root;
            while(temp)
            {
                if(nodeData < temp->data)   {
                    if(!temp->left) {
                        temp->left = node;
                        break;
                    }
                    temp = temp->left;
                }
                else if(nodeData > temp->data) {
                    if(!temp->right) {
                        temp->right = node;
                        break;
                    }
                    temp = temp->right;
                }
                else if(nodeData == temp->data) {
                    cout<<nodeData<<" insert is not possible."<<endl;
                    break;
                }
            }
            // cout<<nodeData<<" insert is not possible."<<endl;
        }
    }

    bool hasData(int val) const {
        TreeNode* temp = root;
        if(!temp) return false;
        while(temp)
        {
            if(val < temp->data)   {
                if(temp->left)
                    temp = temp->left;
                else return false;
            }
            else if(val > temp->data) {
                if(temp->right)
                    temp = temp->right;
                else return false;
            }
            else if(val == temp->data) {
                return true;
            }
        }
        return false;
    }

    TreeNode* dataNode(int val) const {
        TreeNode* temp = root;
        if(!temp) return NULL;
        while(temp)
        {
            if(val < temp->data)   {
                if(temp->left)
                    temp = temp->left;
                else return NULL;
            }
            else if(val > temp->data) {
                if(temp->right)
                    temp = temp->right;
                else return NULL;
            }
            else if(val == temp->data) {
                return temp;
            }
        }
        return NULL;
    }

    TreeNode* headNode(TreeNode* node)    {
        TreeNode* temp;
        if(root == node)    return NULL;
        if(root->left == node || root->right == node) return root;
        temp = headNode(root->right);
        if(!temp)   {
            temp = headNode(root->right);
        }
        return temp;
    }

    void deleteData(int val) {
        TreeNode* t = dataNode(val);
        if(!t) return;
        else if(!t->left && !t->right)   {
            delete t;
        }
        else if(!t->left || !t->right)   {
            TreeNode* t = dataNode(val);
            TreeNode* h = headNode(t);
            
        }
    }

    void printTree() const {
        if(!root)  return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            cout<<temp->data<<": ";
            if(temp->left) {
                cout<<"L= "<<temp->left->data<<" ";
                q.push(temp->left);
            }
            if(temp->right) {
                cout<<"R= "<<temp->right->data<<" ";
                q.push(temp->right);
            }
            cout<<endl;
        }
    }
};

int main()  {
    BST t;
    t.insert(4);
    t.insert(2);
    t.insert(3);
    t.insert(1);
    t.insert(6);
    t.insert(7);
    t.insert(5);

    t.printTree();

    int val;
    cin>>val;
    if(t.hasData(val))    {
        cout<<val<<" is present"<<endl;
    }
    else    {
        cout<<val<<" is not present"<<endl;
    }
    
    // delete &t;
    t.deleteN();
    // t.printTree();
    return 0;
}