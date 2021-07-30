/*
 * File: ReverseQueue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

/* Function prototypes */

void reverseQueue(Queue<string> & queue);
void listQueue(Queue<string> & queue);

/* Test program */

int P4ReverseQueue() {
   Queue<string> line;
   line.enqueue("Genesis");
   line.enqueue("Exodus");
   line.enqueue("Leviticus");
   line.enqueue("Numbers");
   line.enqueue("Deuteronomy");
   listQueue(line);
   reverseQueue(line);
   listQueue(line);
   return 0;
}

/*
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(Queue<string> & queue) {
    Stack<string> stack;
    while (!queue.isEmpty()){
        stack.push(queue.dequeue());
    }
    if(queue.isEmpty()){
        while(!stack.isEmpty()){
            queue.enqueue(stack.pop());
        }
    }


    }   //To do


/*
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(Queue<string> & queue) {
   Queue<string> copy = queue;
   cout << "The queue contains: ";
   while (!copy.isEmpty()) {
      cout << copy.dequeue() << " ";
   }
   cout << endl;
}
