#include "Stabla_template.h"

template <typename T>
int BinaryTree<T>::changeValues(shared_ptr<Node<T>> &node) {
   if (node) {
      T oldValue = node->item;
      node->item = changeValues(node->left) + changeValues(node->right);
      return oldValue + node->item;
   }
   return 0;
}

int main(void) {
   BinaryTree<int> tree;
   tree.insert(4);
   tree.insert(2);
   tree.insert(6);
   tree.insert(3);
   tree.insert(1);
   tree.insert(7);
   tree.insert(5);

   tree.printTree();
   tree.changeValues();
   tree.printTree();

   return 0;
}