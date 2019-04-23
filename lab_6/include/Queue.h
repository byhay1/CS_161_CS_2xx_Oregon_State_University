#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{

private:

    class QueueNode
    {
    private:
        int data;

    public:
        QueueNode* next;

        int head() const
        {
            return data;
        }

        QueueNode* tail() const
        {
            return next;
        }

        QueueNode(int val, QueueNode* prev) : data(val), next(prev) { }
    };


private:
    QueueNode* rear;
    QueueNode* front;

public:
    void add(int);
    int remove();
};

#endif // QUEUE_H
