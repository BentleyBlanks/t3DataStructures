#ifndef T3_HEAP_H
#define T3_HEAP_H

#include <Tree/t3BinaryTree.h>
#include <stdio.h>

// 最大堆
class t3Heap:public t3BinaryTree<t3TreeNode>
{
public:
    t3Heap();
    
    bool isFull();
    
    bool isEmpty();
    
    void insert(int data);
    
    // 删除堆中最大的元素
    t3TreeNode* remove();
};

#endif
