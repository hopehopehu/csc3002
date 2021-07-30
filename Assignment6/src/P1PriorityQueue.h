/*
 * File: pqueue.h
 * --------------
 * This file exports the PriorityQueue class, a collection in which values
 * are processed in priority order.
 */

#ifndef _pqueue_h
#define _pqueue_h

#include "vector.h"
#include "error.h"
using namespace std;

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a priority queue in which values
 * are processed in order of priority.  As in conventional English usage,
 * lower priority numbers correspond to higher effective priorities, 
 * so that a priority 1 item takes precedence over a priority 2 item.
 */
int PriorityQueueTest();

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> pq;
 * -----------------------------------
 * Initializes a new priority queue, which is initially empty.
 */

   PriorityQueue();

/*
 * Destructor: ~PriorityQueue
 * --------------------------
 * Frees any heap storage associated with this priority queue.
 */

   virtual ~PriorityQueue();



/*
 * Method: size
 * Usage: int n = pq.size();
 * -------------------------
 * Returns the number of values in the priority queue.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (pq.isEmpty()) ...
 * ----------------------------
 * Returns true if the priority queue contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: pq.clear();
 * ------------------
 * Removes all elements from the priority queue.
 */

   void clear();

/*
 * Method: enqueue
 * Usage: pq.enqueue(value, priority);
 * -----------------------------------
 * Adds value to the queue with the specified priority.  
 * Lower priority numbers correspond to higher priorities, 
 * which means that all 
 * priority 1 elements are dequeued before any priority 2 elements.
 */

   void enqueue(ValueType value, double priority);

/*
 * Method: dequeue
 * Usage: ValueType first = pq.dequeue();
 * --------------------------------------
 * Removes and returns the highest priority value.  
 * If multiple entries in
 * the queue have the same priority, 
 * those values are dequeued in the same
 * order in which they were enqueued.
 */

   ValueType dequeue();

/*
 * Method: peek
 * Usage: ValueType first = pq.peek();
 * -----------------------------------
 * Returns the value of highest priority in the queue, without removing it.
 */

   ValueType peek() const;

/*
 * Method: peekPriority
 * Usage: double priority = pq.peekPriority();
 * -------------------------------------------
 * Returns the priority of the first element in the queue, 
 * without removing it.
 */

   double peekPriority() const;

/*
 * Method: toString
 * Usage: string str = pq.toString();
 * ----------------------------------
 * Converts the queue to a printable string representation.
 */

   std::string toString();

/* Private section */

/**********************************************************************/
/* Note: Everything below this point in the file is logically part    */
/* of the implementation and should not be of interest to clients.    */
/**********************************************************************/

/*
 * Implementation notes: PriorityQueue data structure
 * --------------------------------------------------
 * The PriorityQueue class is implemented using a data structure called a
 * heap.
 */

private:

/* Type used for each heap entry */

   struct HeapEntry {
      ValueType value;

      double priority;

      long sequence; 
      /* order of enqueue, which used for recording the order of which the elements are inserted, 
      /* i.e.: when two elements are of the same priority, 
       * it depends on the order of the sequence that
       * the first inserted element should be dequeued first
       */ 

   };

/* Instance variables */

   Vector<HeapEntry> heap;
   long enqueueCount; // to record the sequence
   int count;         // to record the number of elements in the PriorityQueue
   int capacity;      // capacity of the heap
   int backIndex;
/* Private function prototypes */

   void enqueueHeap(ValueType & value, double priority); 
   ValueType dequeueHeap();
   bool takesPriority(int i1, int i2);
   void swapHeapEntries(int i1, int i2);

};

//extern void error(std::string msg);

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
   clear();
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * -----------------------------------------------
 * All of the dynamic memory is allocated in the Vector class, so no work
 * is required at this level.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
   /* Empty */
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
   /* TODO */
   return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
   /* TODO */
   return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
   /* TODO */
   heap.clear();
   count = 0;
   enqueueCount = 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
   /* TODO */
   if (count == heap.size()) heap.add(HeapEntry());
   int index = count++;
   heap[index].value = value;
   heap[index].priority = priority;
   heap[index].sequence = enqueueCount++;
   if (index == 0 || takesPriority(backIndex, index)) backIndex = index;
   while (index > 0) {
       int parent = (index - 1) / 2;
       if (takesPriority(parent, index)) break;
       swapHeapEntries(parent, index);
       index = parent;
   }
}

/*
 * Implementation notes: dequeue, peek, peekPriority
 * -------------------------------------------------
 * These methods must check for an empty queue and report an error if there
 * is no first element.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
   /* TODO */
   if (count == 0) error("this is a empty queue");
   count--;
   bool Back = (backIndex == count);
   ValueType value = heap[0].value;
   swapHeapEntries(0, count);
   int index = 0;
   while (true) {
       int left = 2 * index + 1;
       int right = 2 * index + 2;
       if (left >= count) break;
       int child = left;
       if (right < count && takesPriority(right, left)) child = right;
       if (takesPriority(index, child)) break;
       swapHeapEntries(index, child);
       index = child;
   }
   if (Back) backIndex = index;
   return value;

}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
  /* TODO */
  if (isEmpty()) error("the queue is empty");
  return heap[0].value;
}

template <typename ValueType>
double PriorityQueue<ValueType>::peekPriority() const {
   /* TODO */
   if (isEmpty()) error("the queue is empty");
   return heap[0].priority;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::takesPriority(int i1, int i2) {
   /* compare the priority of two elements，
   /* when their priorities are equal, comparing based on the sequence */
   /* TODO */
   if (heap[i1].priority < heap[i2].priority) return true;
   if (heap[i1].priority > heap[i2].priority) return false;
   return (heap[i1].sequence < heap[i2].sequence);
}

template <typename ValueType>
void PriorityQueue<ValueType>::swapHeapEntries(int i1, int i2) {
   /* TODO */
   HeapEntry entry = heap[i1];
   heap[i1] = heap[i2];
   heap[i2] = entry;
}

template <typename ValueType>
std::string PriorityQueue<ValueType>::toString() {
  /* convert the PriorityQueue into a printable String */
  /* TODO */
  ostringstream os;
  os << *this;
  return os.str();
}

template <typename ValueType>
std::ostream & operator<<(std::ostream & os,
                          const PriorityQueue<ValueType> & pq) {
   /* give the output of all the elements in queue(not dequeue)
   /* i.e.: cout << pq gives the output of all the content in current queue without change pq */
   /* TODO */
   os << "{";
   PriorityQueue<ValueType> copy = pq;
   int len = pq.size();
   for (int i = 0; i < len; i++) {
       if (i > 0) os << ", ";
       os << copy.peekPriority() << ":";
       writeGenericValue(os, copy.dequeue(), true);
   }
   return os << "}";
}

#endif
