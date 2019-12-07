#include<bits/stdc++.h>
#include<stack> 
using namespace std;

template<class T>
class TreeNode;
template<class T>
class Tree;

template<class T>
class TreeNode{

    public:
    T data;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;

    public:
    TreeNode(T data);
    void insert(T value);
};

template<class T>
class Tree{

    TreeNode<T>* Delete(TreeNode<T> *temp , T value);
    public:
    TreeNode<T> *root;
    Tree();
    void insert(T data);
    void BFS();
    TreeNode<T>* getRoot();
    void Delete(T value);
};

template<class T>
TreeNode<T>::TreeNode(T data)
    {
        this->data = data;
        leftNode = rightNode =   NULL;
    }

template<class T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}

template<class T>
void TreeNode<T>::insert(T value)
    {
        if(data == value)
            return;
        
        if(value < data)
        {
            if(leftNode == NULL)
            leftNode = new TreeNode<T>(value) ;
            else
            leftNode->insert(value);                
            
        } else if(value > data)
        {
            if(rightNode == NULL)
            rightNode = new TreeNode<T>(value) ;
            else
            rightNode->insert(value);                
            
        }
    }

template<class T>
Tree<T>::Tree()
    {
        root = NULL;
    }
template<class T>
TreeNode<T>* Tree<T>::Delete(TreeNode<T> *temp ,T value)
{
    if(temp == NULL)
    return temp;
    if(temp->data > value)
    temp->leftNode = Delete(temp->leftNode, value);
    else if(temp->data < value)
    temp->rightNode = Delete(temp->rightNode , value);
    else
    {
    

        if(temp->leftNode == NULL && temp->rightNode == NULL)
        {
            delete temp;
            temp = NULL;
            return temp;
        }
        else if (temp->leftNode == NULL || temp->rightNode == NULL)
        {
            if (temp->leftNode == NULL)
            {
                TreeNode<T> *oldNode = temp;
                temp = temp->rightNode;
                delete oldNode;
                return temp;
            }
            else
            {
                TreeNode<T> *oldNode = temp;
                temp = temp->leftNode;
                delete oldNode;
                return temp;
            }
        }
        else
        {
            TreeNode<T> *leftMaxNode = maxNode(temp->leftNode);
            temp->data = leftMaxNode->data;
            temp->leftNode = Delete(temp->leftNode, leftMaxNode->data);
        }
    }       
    return temp;
    
}
template<class T>
void Tree<T>::Delete(T value)
{
    root = Delete(root , value);
}
template<class T>
void Tree<T>::insert(T data)
    {
        if(root == NULL)
        root = new TreeNode<T>(data);
        else
        root->insert(data);
    }
template<class T>
void Tree<T>::BFS()
{
    TreeNode<T> *temp = root;
    stack< TreeNode<T>* > s;

    s.push(temp);

    while (!s.empty())
    {
        TreeNode<T> *temp2 = s.top();
        s.pop();
        cout<<temp2->data<<" ";

        if(temp2->rightNode != NULL)
        s.push(temp2->rightNode);
        if(temp2->leftNode != NULL)
        s.push(temp2->leftNode);

    }
    
}
int main()
{
    Tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(2);
    tree.insert(10);
    tree.insert(11);
    tree.insert(15);
//    TreeNode<int> *temp = tree.getRoot();
//    cout<<endl;
    tree.BFS();
    return 0;
}
