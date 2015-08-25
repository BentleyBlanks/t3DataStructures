#include <Tree/t3BinaryTree.h>

#include <Common/t3Test.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    int preorder[] = {7, 10, 4, 3, 1, 2, 8, 11};
    int inorder[] = {4, 10, 3, 1, 7, 11, 8, 2};
    int length = sizeof(preorder) / sizeof(preorder[0]);
    
    t3BinaryTree tree;
    
    tree.create(preorder, inorder, length);
    
    t3Log("---------------------preorder---------------------\n");
    tree.preorder();
    
    t3Log("---------------------inorder---------------------\n");
    tree.inorder();
    
    t3Log("---------------------postorder---------------------\n");
    tree.postorder();
    
    t3Log("---------------------levelorder---------------------\n");
    tree.levelorder();
    
    return 0;
}