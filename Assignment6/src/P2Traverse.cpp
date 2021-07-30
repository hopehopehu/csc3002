/*
 * File: TraverseTest.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack
 * or
 * reimplements the breadth-first search algorithm using an
 * explicit queue.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "set.h"
#include "simplegraph.h"
#include "stack.h"
#include "queue.h"
#include "foreach.h"
#include "console.h"

using namespace std;

/* Main program */
void dfs(Node *start);
void bfs(Node *start);

int TraverseTest() {
   SimpleGraph airline;
   ifstream infile("AirlineGraph.txt");
   readGraph(airline, infile);
   dfs(airline.nodeMap.get("Portland"));
   bfs(airline.nodeMap.get("Portland"));
   return 0;
}


void dfs(Node *start) {
   /* TODO */
   /* make sure that your implemantation is based on an explicit Stack */
   Set<Node*> searched;
   if (searched.contains(start)) return;
   cout<< start -> name<< endl;
   searched.add(start);
   for (Arc *arc : start -> arcs){
       dfs(arc->finish);
   }

}

void bfs(Node *start) {
    /* TODO */
   /* make sure that your implemantation is based on an explicit Queue */
    Set<Node*> searched;
    Queue<Node*> que {start};
    cout<< start->name <<endl;
    searched.add(start);


    Node *origin, *dest;
    while (!que.isEmpty()) {
        origin = que.dequeue();
        for (Arc* arc : origin->arcs) {
            dest = arc->finish;
            if (!searched.contains(dest)) {
                cout<< dest->name << endl;
                searched.add(dest);
                que.enqueue(dest);
            }
        }
    }

}
