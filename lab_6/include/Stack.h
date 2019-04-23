#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{

private:

    class StackNode
    {
    private:
        int data;
        StackNode* tail_;

    public:
        int head() const
        {
            return data;
        }

        StackNode* tail() const
        {
            return tail_;
        }

        StackNode(int val, StackNode* prev) : data(val), tail_(prev) { }
    };


private:
    StackNode* top;

    bool empty() const
    {
        return top == NULL;
    }

public:
    ~Stack()
    {
        delete top;
    }

    void add(int);
    int remove();
};

#endif // STACK_H
