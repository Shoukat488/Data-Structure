#include<bits/stdc++.h> 
#include <queue>
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
    void traverseInOrder();
};

template<class T>
class Tree{

    public:
    TreeNode<T> *root;
    public:
    Tree();
    void insert(T data);
    void traverseInOrder();
    TreeNode<T>* getRoot();
	bool search(T value);
    void BFS();
};

template<class T>
TreeNode<T>::TreeNode(T data)
    {
        this->data = data;
        leftNode = rightNode =  NULL;
    }

template<class T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}
template<class T>
void Tree<T>::BFS()
{
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);    
        
    }
    cout<<endl;
}
template<class T>
void TreeNode<T>::traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }

template<class T>
Tree<T>::Tree()
    {
        root = NULL;
    }

template<class T>
bool Tree<T>::search(T value)
{
	bool flag = false;
	stack<TreeNode<T> *> tempStack;
	TreeNode<T> *temp = root;

	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
			if(temp->data == value)
			{
				flag = true;
				break;
			}
			tempStack.push(temp);
			temp = temp->leftNode;
		}
		if(!tempStack.empty())
		{
			temp = tempStack.top();
			tempStack.pop();
		}
	

		temp = temp->rightNode;
		
	}
	return flag == true;
}

template<class T>
void Tree<T>::insert(T value)
    {
        
       if(root == NULL)
        root = new TreeNode<T>(value);
        else
        {
        	if(root->data == value)
            return;
            
            queue<TreeNode<T> * > q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode<T> *temp = q.front();
				q.pop();
                if(temp->leftNode != NULL)
                q.push(temp->leftNode);
                else
                {
	                temp->leftNode = new TreeNode<T>(value);
	                break;
                }
                if(temp->rightNode != NULL )
                q.push(temp->rightNode);
                else
                {
                    temp->rightNode = new TreeNode<T>(value);
                    break;
                }
            }
        }
    }
template<class T>
void Tree<T>::traverseInOrder()
    {
        root->traverseInOrder();
    }

int main()
{
    Tree<int> tree;

    tree.insert(4);
    tree.insert(1);
    tree.insert(12);
    tree.insert(10);
    tree.insert(32);
    tree.insert(65);
    tree.traverseInOrder();
    cout<<endl;
    tree.BFS();
}