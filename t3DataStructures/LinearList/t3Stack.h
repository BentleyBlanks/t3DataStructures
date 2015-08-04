#ifndef T3_STACK_H
#define T3_STACK_H

template <class T>
class t3Stack
{
public:
    t3Stack();
    
    // 放入给定值的拷贝
    void push(T &value);
    
    bool isEmpty();
    
    bool isFull();
    
    // 获取栈顶元素值
    T get();
    
    // 弹出栈顶元素并返回
    T pop();
    
    void print();
    
private:
    // 尽量不要扩建，效率降低
    void enlarge();
    
    // 栈头
    T *head;
};

#endif