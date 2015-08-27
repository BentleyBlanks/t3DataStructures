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
        if(previous && !previous->rightChild && !previous->rightThread)
        {
            previous->rightThread = true;
            previous->rightChild = current;
        }
        
        previous = current;
        
        threading(current->rightChild);
    }
}

void t3ThreadedBinaryTree::inorder()
{
    if(!tree)
        return;
    
    t3ThreadTreeNode *h;
    h = tree;
    // 找到根的最左端
    while(!h->leftThread)
        h = h->leftChild;
    
    t3Log(" %d ", h->data);
    
    // 直到找到最后一个后继结点
    while(h->rightChild)
    {
        if(h->rightThread)
            h = h->rightChild;
        else
        {
            h = h->rightChild;
            
            // 找到该节点的最左端结点
            while(!h->leftThread)
                h = h->leftChild;
        }
        t3Log(" %d ", h->data);
    }
}