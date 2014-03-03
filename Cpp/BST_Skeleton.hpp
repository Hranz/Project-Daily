/*
   Programmer: Kristoffer Larson
   Date: March 2, 2014
   
   Description: The skeleton for a BST in C++ using templates.

*/

#include <cstdlib>
#include <iostream>

template <class T>
class TreeNode {
   
   public:
      T item;
      TreeNode<T> leftChild;
      TreeNode<T> rightChild;
      
      TreeNode(T newItem) {
         item = newItem;
         leftChild = NULL;
         rightChild = NULL;
      } // end constructor
      
      TreeNode(T newItem, TreeNode<T> left, TreeNode<T> right) {
         item = newItem;
         leftChild = left;
         rightChild = right;
      } // end constructor
};

template <class T>
class BinaryTreeBasis {

   protected: 
      TreeNode<T> root;
      
   public:
      BinaryTreeBasis() {
         root = NULL;
      } // end default constructor
      
      BinaryTreeBasis(T rootItem) {
         root = new TreeNode<T>(rootItem, NULL, NULL);
      } // end constructor
      
      bool isEmpty() {
      // Returns true if the tree is empty, else returns false.
         return root == NULL;
      } // end isEmpty
      
      void makeEmpty() {
      // Removes all nodes from the tree.
         root = NULL;
      } // end makeEmpty
      
      T getRootItem() {
      // Returns the item in the tree's root.
         if (root == NULL) {
            std::cout << "TreeException: Empty tree" << std::endl;
            exit(0);
         }
         else {
            return root.item;
         } // end if
      } // end getRootItem

};
