/*
   Programmer: Kristoffer Larson
   Date: January 28, 2014
   
   Description: Creates a TreeNode with an item and pointers to children.
      
*/

#ifndef null
#define null 0
#endif

using namespace std;

template <class T> class TreeNode {
   private:
      T item;
      TreeNode<T> *leftChild;
      TreeNode<T> *rightChild;
      
   public:
      TreeNode(T newItem) {
         item = newItem;
         leftChild = null;
         rightChild = null;
      }
};

int main() {
   TreeNode<int> TreeNode(5);
   
   return 0;
}
