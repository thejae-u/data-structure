#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    Stack<float> fs1;
    fs1.Push(10.8f);
    fs1.Push(10.2f);
    fs1.Push(10.100f);
    fs1.Print();

    List<float> fl1;
    fl1.Add(10.1123f);
    fl1.Add(10.1233f);
    fl1.Add(10.12345f);
    fl1.Add(10.3351f);
    fl1.Print();
    fl1.RemoveAt(3);
    fl1.Print();

    Queue<std::string> sq1;
    sq1.Enqueue("Hello");
    sq1.Enqueue("My");
    sq1.Enqueue("Name");
    sq1.Enqueue("Is");
    sq1.Print();
    sq1.Dequeue();
    sq1.Print();
}