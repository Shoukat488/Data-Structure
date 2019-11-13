#include<iostream>
using namespace std;
class TreeNode;

class TreeNode{

    public:
    int data;
    TreeNode *leftNode;
    TreeNode *rightNode;

    public:

    TreeNode(int data)
    {
        this->data = data;
        leftNode = rightNode =   NULL;
    }
    
    void insert(int value)
    {
        if(data == value)
        return;

        if(value < data)
        {
            if(leftNode == NULL)
            data = value;
            else
            leftNode->insert(value);                
            
        } else if(value > data)
        {
            if(rightNode == NULL)
            data = value;
            else
            rightNode->insert(value);                
            
        }
    }

    void traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }
  
};

class Tree{

    private:
    TreeNode *root;

    public:
    Tree()
    {
        root = NULL;
    }

    void insert(int data)
    {
        if(root == NULL)
        root = new TreeNode(data);
        else
        root->insert(data);
    }
    void traverseInOrder()
    {
        root->traverseInOrder();
    }
};
int main()
{

    Tree *tree = new Tree();

    tree->insert(3);
    tree->insert(5);
    tree->insert(20);
    tree->insert(1);
    tree->insert(7);
    tree->insert(4);
    tree->insert(10);

    tree->traverseInOrder();
}
