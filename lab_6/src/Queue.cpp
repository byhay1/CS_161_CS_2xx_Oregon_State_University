#include "Queue.h"

void Queue::add(int value)
{
    QueueNode *temp = new QueueNode(value, NULL);

    if(front == NULL)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }

    rear = temp;
}

int Queue::remove()
{

    int result;

    if(front == NULL)
    {
        std::cout << "Queue is Emtpty" << std::endl;
        return -1;
    }
    else
    {
        QueueNode* temp = front;

        front = front->next;
        result = temp->head();

        delete temp;
    }

    return result;
}
