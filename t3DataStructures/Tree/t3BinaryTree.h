#ifndef T3_BINARYTREE_H
#define T3_BINARYTREE_H

#include <Common/t3DataStructuresSettings.h>
#include <iostream>

class t3TreeNode
{
public:
    t3TreeNode(int data, t3TreeNode* leftChild,  t3TreeNode* rigthChild):data(data), leftChild(leftChild), rightChild(rigthChild){}
    
    t3TreeNode(int data):data(data), leftChild(NULL), rightChild(NULL){}
    
    t3TreeNode():data(0), leftChild(NULL), rightChild(NULL){}
    
    int data;
    t3TreeNode *leftChild, *rightChild;
};

// 原计划将树设定为模板 不过为练手 这里简单的用int直接代替data数据类型
class t3BinaryTree
{
public:
    t3BinaryTree();
    
    bool create(int preorder[], int inorder[], int length);

    void preorder();
    
    void inorder();
    
    void postorder();
    
    void levelorder();
    
    t3TreeNode *tree;
    
private:
    
    t3TreeNode* preorder(t3TreeNode* root);
    
    t3TreeNode* inorder(t3TreeNode* root);
    
    t3TreeNode* postorder(t3TreeNode* root);
    
    // offset为当前子树的相对序号
    t3TreeNode* buildInorderPreorder(int preorder[], int length, int offset, bool bRoot);
    
    int mapIndex[T3_BINARTTREE_MAPINDEX_LENGTH];
};

#endif
