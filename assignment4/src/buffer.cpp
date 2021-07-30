/*
 * File: buffer.cpp (list version without dummy cell)
 * --------------------------------------------------
 * This file implements the EditorBuffer class using a linked
 * list to represent the buffer.
 */

#include <iostream>
#include "buffer.h"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/*
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer() {
    Cell* cp = start;
    while(cp != NULL){
        Cell *next = cp ->next;
        delete cp;
        cp = next;
    }
    //TODO

}

/*
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
    if (cursor -> next -> next!= NULL){
        cursor =  cursor -> next;
    }
   //TODO
}

void EditorBuffer::moveCursorBackward() {
    if (cursor->prev != NULL){
        cursor = cursor -> prev;

    //TODO

   }
}

void EditorBuffer::moveCursorToStart() {
    cursor = start;
   //TODO


}

void EditorBuffer::moveCursorToEnd() {
    while(cursor -> next != NULL){
        moveCursorForward();
    }
   //TODO


}

/*
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {
    Cell *incert_cell = new Cell;
    incert_cell -> ch = ch;
    incert_cell -> next = cursor -> next;
    incert_cell -> next -> prev = incert_cell;
    cursor -> next = incert_cell;
    incert_cell -> prev = cursor;
    cursor = incert_cell;
    //TODO

}

void EditorBuffer::deleteCharacter() {
    if(cursor -> next -> next != NULL){
        Cell *cell_deleted = new Cell;
        cell_deleted = cursor -> next;
        cursor -> next = cursor -> next -> next;
        cursor -> next -> prev = cursor;
        delete cell_deleted;

    //TODO


   }
}

/*
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const {
    string get_text = "";
    for (Cell* traverser = start; traverser != NULL; traverser = traverser -> next){
        get_text += traverser -> ch;
    }
    return get_text;
    //TODO


}

int EditorBuffer::getCursor() const {
    int cursor_index = 0;
    for (Cell* traverser; traverser != cursor; traverser = traverser -> next){
        cursor_index++;
    }
    return cursor_index;
    //TODO


}
