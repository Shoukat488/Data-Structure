#include<bits/stdc++.h> 
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
    void totalLeafs(TreeNode<T> *temp , int *count);
    void insert(T value);
    void traverseInOrder();
};

template<class T>
class Tree{

    TreeNode<T>* Delete(TreeNode<T> *temp , T value);
    public:
    TreeNode<T> *root;
    public:
    Tree();
    void insert(T data);
    void traverseInOrder();
    TreeNode<T>* getRoot();
    bool search(T value);
    int totalLeafs();
    void Delete(T value);
};
template<class T>
void TreeNode<T>::totalLeafs(TreeNode<T> *temp , int *count)
{
    if(temp == NULL)
    return;
    if(temp->leftNode == NULL && temp->rightNode == NULL)
    (*count)++;
    if(temp->leftNode != NULL)
    totalLeafs(temp->leftNode , count);
    if(temp->rightNode != NULL)
    totalLeafs(temp->rightNode , count);
}
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
void TreeNode<T>::traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }
template<class T>
int Tree<T>::totalLeafs()
{
	int count = 0 ;
    root->totalLeafs(root , &count);
    return count;
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
void printPostorder(TreeNode<T> * node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->leftNode); 
  
    // then recur on right subtree 
    printPostorder(node->rightNode); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
template<class T>
void printPreorder(TreeNode<T>* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->leftNode);  
  
    /* now recur on right subtree */
    printPreorder(node->rightNode); 
}  
 
template<class T>
void Tree<T>::traverseInOrder()
    {
        root->traverseInOrder();
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
TreeNode<T>* searchNode(TreeNode<T> *root , T value)
{
	bool flag = false;
    TreeNode<T> * flagNode;
	stack<TreeNode<T> *> tempStack;
	TreeNode<T> *temp = root;

	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
			if(temp->data == value)
			{
				flag = true;
                flagNode = temp;
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

	return flagNode;
}
template<class T>
TreeNode<T>* minNode(TreeNode<T> *temp)
{
    TreeNode<T> *prev;
		while (temp != NULL)
		{
            prev = temp;
			temp = temp->leftNode;
		}
        return prev;
}
template<class T>
TreeNode<T>* maxNode(TreeNode<T> *temp)
{
    TreeNode<T> *prev;
		while (temp != NULL)
		{
            prev = temp;
			temp = temp->rightNode;
		}
        return prev;
}
template<class T>
int TreeHeight(TreeNode<T> *root)
{
    if(root == NULL)
    return 0;
    else
    {
    int lDepth = TreeHeight(root->leftNode);
    int rDepth = TreeHeight(root->rightNode);

    if(lDepth > rDepth)
    return lDepth + 1;
    else
    return rDepth + 1;
    }
}

int main()
{
    Tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(1);
    tree.traverseInOrder();
    TreeNode<int> *temp = tree.getRoot();
    cout<<endl<<tree.search(4);
    tree.Delete(4);
    cout<<endl;
    tree.traverseInOrder();
    cout<<endl<<"No of leaf nodes :"<< tree.totalLeafs()<<endl;
    cout<<"Height Tree : "<<TreeHeight(temp);
}
