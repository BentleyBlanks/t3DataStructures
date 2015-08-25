#include <Tree/t3BinaryTree.h>
#include <Common/t3Test.h>
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <LinearList/t3Stack.h>

t3BinaryTree::t3BinaryTree()
{
    
}

bool t3BinaryTree::create(int preorder[], int inorder[], int length)
{
    if(!preorder || !inorder)
    {
        t3PrintError("前序/中序序列不能为空");
        return false;
    }
    
    //int length = sizeof(preorder) / sizeof(preorder[0]);
    for(int i=0; i<length; i++)
    {
        // --!此处极其可能造成大量空间浪费
        mapIndex[inorder[i]] = i;
    }
    
    buildInorderPreorder(preorder, length, 0, true);
    
    return true;
}

// offset为当前子树在先序序列中的起始序号
t3TreeNode* t3BinaryTree::buildInorderPreorder(int preorder[], int length, int offset, bool bRoot)
{
    if(length == 0)
        return NULL;
    int rootValue = preorder[0];
    // 当前子树根节点相对序号
    int i = mapIndex[rootValue] - offset;
    
    t3TreeNode* root = new t3TreeNode(rootValue);
    root->leftChild = buildInorderPreorder(preorder+1, i, offset, false);
    root->rightChild = buildInorderPreorder(preorder+i+1, length - i - 1, offset + i + 1, false);
    
    // 是否为根
    if(bRoot)
        tree = root;
    
    return root;
}

void t3BinaryTree::preorder()
{
    preorder(tree);
}

void t3BinaryTree::inorder()
{
    inorder(tree);
}

void t3BinaryTree::postorder()
{
    postorder(tree);
}

void t3BinaryTree::levelorder()
{
    t3Stack<t3TreeNode*> stack;
    
    if(!tree)
        return;
    
    stack.push(tree);
    while(true)
    {
        if(stack.isEmpty())
            break;
        
        t3TreeNode *node = stack.pop();
        t3Log("% d ", node->data);
        if(node->leftChild)
            stack.push(node->leftChild);
        if(node->rightChild)
            stack.push(node->rightChild);
    }
}

t3TreeNode* t3BinaryTree::preorder(t3TreeNode* root)
{
    if(!root)
        return NULL;
    
    t3Log(" %d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
    
    return root;
}

t3TreeNode* t3BinaryTree::inorder(t3TreeNode* root)
{
    if(!root)
        return NULL;
   
    inorder(root->leftChild);
    t3Log(" %d ", root->data);
    inorder(root->rightChild);
    
    return root;
}

t3TreeNode* t3BinaryTree::postorder(t3TreeNode* root)
{
    if(!root)
        return NULL;
    
    postorder(root->leftChild);
    postorder(root->rightChild);
    t3Log(" %d ", root->data);
    
    return root;
}