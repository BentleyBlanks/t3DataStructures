#include <Tree/t3ThreadedBinaryTree.h>
t3ThreadTreeNode *previous;

t3ThreadedBinaryTree::t3ThreadedBinaryTree()
{
    
}

void t3ThreadedBinaryTree::threading()
{
    previous = NULL;
    threading(tree);
}

void t3ThreadedBinaryTree::threading(t3ThreadTreeNode *current)
{
    if(current)
    {
        threading(current->leftChild);
    
        // 空 / false
        if(!current->leftChild && !current->leftThread)
        {
            current->leftThread = true;
            current->leftChild = previous;
        }
        
        // 空 / 空 / false
        if(!previous && !previous->rightChild && !previous->rightThread)
        {
            previous->rightThread = true;
            previous->rightChild = current;
        }
        
        previous = current;
        
        threading(current->rightChild);
    }
}