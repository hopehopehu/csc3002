/*
 * File: stringmap.cpp
 * -------------------
 * This file implements the stringmap.h interface using a hash table
 * with open addressing as the underlying representation.
 */

#include <iostream>
#include <string>
#include "error.h"
#include "stringmap.h"
using namespace std;

/* Constant definitions */

   const int StringMap::INITIAL_BUCKET_COUNT = 13;
   const double StringMap::REHASH_THRESHOLD = 0.7;



/*
 * Implementation notes: HashMap constructor and destructor
 * --------------------------------------------------------
 * The constructor allocates the array of buckets and initializes each
 * bucket to the empty list.  The destructor frees the allocated cells.
 */

StringMap::StringMap() {
   nBuckets = INITIAL_BUCKET_COUNT;
   buckets = new KeyValuePair[nBuckets];
   clear();
}

StringMap::~StringMap() {
   delete[] buckets;
}

/*
 * Implementation notes: get
 * -------------------------
 * The get method calls findKey to search the buckets array for the
 * matching key.  If no key is found, get returns the empty string.
 */

string StringMap::get(const string & key) const {
   int index = findKey(key);
   return (index == -1) ? "" : buckets[index].value;
}

/*
 * Implementation notes: put
 * -------------------------
 * The put method calls insertKey to search the bucket array for a matching
 * key.  If a key already exists, put simply resets the value field.  If no
 * matching key is found, put adds a new entry in the first free slot.
 */

void StringMap::put(const string & key, const string & value) {
   if ((double) count / nBuckets > REHASH_THRESHOLD) {//reach its load factor
      rehash(2 * nBuckets + 1);
   }
   int index = insertKey(key);//less than its load factor
   buckets[index].value = value;
}

int StringMap::size() const {
   return count;
}

bool StringMap::isEmpty() const {
   return count == 0;
}

bool StringMap::containsKey(const string & key) const {
   return findKey(key) != -1;
}

/*
 * Implementation notes: remove
 * ----------------------------
 * This implementation is tricky because removing one key can make later
 * keys inaccessible.  This implementation finds the first key that could
 * have gone in this position (if any) and moves it to this space, repeating
 * that process until an empty entry is found.  A much simpler but less
 * efficient strategy is to rehash after every deletion.
 */

void StringMap::remove(const string & key) {
   int index = findKey(key);
   if (index != -1) {
      buckets[index].occupied = false;
      count--;
      int toFill = index;
      while (true) {
         index = (index + 1) % nBuckets;
         if (!buckets[index].occupied) return;
         if (insertKey(buckets[index].key) == toFill) {
            buckets[toFill].value = buckets[index].value;
            buckets[index].occupied = false;
            toFill = index;
         }
      }
   }
}

void StringMap::clear() {
   for (int i = 0; i < nBuckets; i++) {
      buckets[i].occupied = false;
   }
   count = 0;
}

int StringMap::getNBuckets() {
   return nBuckets;
}

/*
 * Implementation notes: rehash
 * ----------------------------
 * The rehash method iterates over the existing key-value pairs, entering
 * them into a new table.
 */

void StringMap::rehash(int nBuckets) {
    //TODO
    for (int i = 0; i < nBuckets; i++){
        insertKey(buckets[i].key);
    }
}

/*
 * Private method: findKey
 * Usage: int index = findKey(key);
 * --------------------------------
 * This private method looks for a key in the buckets array.  If the
 * key is found, findKey returns its index.  If no match is founded, the
 * findKey returns -1.
 */

int StringMap::findKey(const string & key) const {
    //TODO
    int index = -1;
    for (int i = 0; i < nBuckets; i++){
        if (buckets[i].occupied == true && buckets[i].key == key){
            index = i;
        }
    }
    return index;
//    int hash_code_key = hashCode_(key);
//    int index = hash_code_key % nBuckets;
//    if (buckets[index].occupied == false){// no key at here
//        index = -1;
//    }
//    else{// there is key at here
//        if (buckets[index].key == key){//same key at here, collision
//            return index;
//        }
//        else{// different element
//            while (index != hash_code_key % nBuckets - 1){
//                index = (index + 1) % nBuckets;
//            }

//        }
//    }
}

/*
 * Private method: insertKey
 * Usage: int index = insertKey(key);
 * ----------------------------------
 * This private method is identical to findKey except that it inserts the
 * key in the correct place if it is not already in the table.
 */

int StringMap::insertKey(const string & key) {
    //TODO
    int correct_place = hashCode_(key);
    if (findKey(key) == -1){//this key is not in the hash map

        while (buckets[correct_place].occupied == true){
            correct_place = (correct_place + 1) % nBuckets;
        }
        buckets[correct_place].key = key;
    }
    count++;
    return correct_place;//same usage with index
}

/*
 * Implementation notes: hashCode_
 * ------------------------------
 * This function takes a string key and uses it to derive a hash code,
 * which is nonnegative integer related to the key by a deterministic
 * function that distributes keys well across the space of integers.
 * The specific algorithm used here is called djb2 after the initials
 * of its inventor, Daniel J. Bernstein, Professor of Mathematics at
 * the University of Illinois at Chicago.
 */

const int HASH_SEED = 5381;               /* Starting point for first cycle */
const int HASH_MULTIPLIER = 33;           /* Multiplier for each cycle      */
const int HASH_MASK = unsigned(-1) >> 1;  /* The largest positive integer   */

int hashCode_(const string & str) {
   unsigned hash = HASH_SEED;
   int n = str.length();
   for (int i = 0; i < n; i++) {
      hash = HASH_MULTIPLIER * hash + str[i];
   }
   return int(hash & HASH_MASK);
}


