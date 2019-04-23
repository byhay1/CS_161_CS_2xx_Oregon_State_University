#include "Stack.h"

void Stack::add(int value) {
    StackNode* currentTop = top;
    top = new StackNode(value, currentTop);
}

int Stack::remove()
{
    if (empty())
    {
        std::cout << "Empty stack!" << std::endl;
    }

    StackNode* tail = top->tail();
    int result = top->head();
    delete top;
    top = tail;

    return result;
}
