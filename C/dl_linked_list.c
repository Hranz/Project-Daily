/*
   Programmer: Kristoffer Larson
   Date: February 15, 2014
   
   Description: Creates a Linked List structure with two
      pointer references. Currently it only acts like a 
      Singly Linked List, and nothing is done with the 
      second pointer.
*/

#include <stdlib.h>

struct dlnode_t { //Defines a dlnode
   struct dlnode_t* left; //Left node pointer
   struct dlnode_t* right; //Right node pointer
   int data; //Data contained
};//End dlnode_t
typedef struct dlnode_t dlnode; //Reference to dlnode_t is now dlnode

dlnode* dl_new_node(int data, dlnode* left, dlnode* right) { //Creates a new dlnode
   dlnode* node = malloc(sizeof *node);
   node->data = data;
   node->left = left;
   node->right = right;
   return node;
}//End dl_new_node

dlnode* dl_insert_front(dlnode* left, dlnode* right, int data) { //Inserts a dlnode in front of given node
   dlnode* node = dl_new_node(data, left, right);
   left = node;
   right = NULL;
   return left; //Returns newly created node with it's pointer
}//End dl_insert_front

int main() {
   dlnode* start = dl_new_node(5, NULL, NULL); //Creates a starting node
   dlnode* place = dl_insert_front(start, NULL, 6); //Links to first node
   dl_insert_front(place, NULL, 7); //Links to second node
   return 0;
}//End main
