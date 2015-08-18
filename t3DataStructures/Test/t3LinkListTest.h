#include <LinkList/t3LinkList.h>
#include <Common/t3Test.h>
#include <Common/t3Timer.h>
#include <iostream>

int main(int argc, char* argv[])
{
    t3SingleLinkList<int> linkList;
    
    t3Log("-------------------------------\n");

    linkList.insert(20);
    linkList.insert(3);
    t3LinkListNode<int>* node = linkList.insert(2);
    linkList.insert(60);
    linkList.insert(28);
    
    linkList.print();
    
    linkList.deleteNode(node);
    
    t3Log("-------------------------------\n");
    linkList.print();
    
    linkList.invert();
    
    t3Log("-------------------------------\n");
    linkList.print();
    
    return 0;
}