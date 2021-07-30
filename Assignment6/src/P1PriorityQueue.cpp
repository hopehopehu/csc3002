/*
 * File: P1PriorityQueue.cpp
 * ---------------------------
 * This file contains a unit test of the PriorityQueue class.
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include "P1PriorityQueue.h"
#include "strlib.h"
using namespace std;

int PriorityQueueTest() {
   PriorityQueue<string> pq;
   assert(pq.size() == 0);
   assert(pq.isEmpty());
   pq.enqueue("A", 1);
   assert(!pq.isEmpty());
   assert(pq.peek() == "A");
   pq.enqueue("D", 3);
   pq.enqueue("C", 2);
   pq.enqueue("B", 1);
   assert(pq.peek() == "A");
   assert(pq.size() == 4);
   assert(pq.toString() == "{1:\"A\", 1:\"B\", 2:\"C\", 3:\"D\"}");
   assert(pq.dequeue() == "A");
   assert(pq.peek() == "B");
   assert(pq.dequeue() == "B");
   assert(pq.dequeue() == "C");
   assert(pq.dequeue() == "D");
   assert(pq.isEmpty());
   return 0;
}
