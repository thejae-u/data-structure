#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    Queue q1;
    q1.Enqueue(100);
    q1.Enqueue(200);
    q1.Enqueue(300);
    q1.Enqueue(400);

    q1.Print();
}
