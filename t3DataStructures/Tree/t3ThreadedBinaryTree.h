#ifndef T3_THREADED_BINARYTREE_H
#define T3_THREADED_BINARYTREE_H

#include <Tree/t3BinaryTree.h>

class t3ThreadTreeNode
{
public:
    t3ThreadTreeNode(int data):leftThread(false), rightThread(false), leftChild(NULL), rightChild(NULL), data(data){}
    // 默认线索全为false
    t3ThreadTreeNode():leftThread(false), rightThread(false), leftChild(NULL), rightChild(NULL), data(0){}
    
    int data;
    bool leftThread, rightThread;
    t3ThreadTreeNode *leftChild, *rightChild;
};

class t3ThreadedBinaryTree:public t3BinaryTree<t3ThreadTreeNode>
{
public:
    t3ThreadedBinaryTree();
    
    void threading();
    
private:
    void threading(t3ThreadTreeNode *current);
};

#endif
