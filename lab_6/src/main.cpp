#include <iostream>
#include <cassert>
#include "Stack.h"
#include "Queue.h"

int main(int argc, const char * argv[])
{


    Stack s;
    s.add(1);
    s.add(2);
    s.add(3);

    assert(s.remove() == 3);
    assert(s.remove() == 2);
    assert(s.remove() == 1);


    Queue q;
    q.add(1);
    q.add(2);
    q.add(3);

    assert(q.remove() == 1);
    assert(q.remove() == 2);
    assert(q.remove() == 3);

    return 0;
}
