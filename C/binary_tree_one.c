/*
   Programmer: Kristoffer Larson
   Date: February 16, 2014
   
   Description: Attempt at a binary tree in C. Something
      is wrong with dl_insert, probably the pointers.
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

dlnode* dl_insert(dlnode* new, int data) { //Inserts a dlnode in front of given node
   dlnode* new_sub_tree;
   int* point = &new->data;
   if (point == NULL) {
      new = dl_new_node(data, NULL, NULL);
      return new;
   } else if (data < new->data) {
      new_sub_tree = dl_insert(new->left, data);
      new->left = new_sub_tree;
      return new;
   } else {
      new_sub_tree = dl_insert(new->right, data);
      new->right = new_sub_tree;
      return new;
   }
}//End dl_insert_front

int main() {
   dlnode* first = dl_new_node(5, NULL, NULL);
   dlnode* second = dl_insert(first, 6);
   
   return 0;
}//End main
