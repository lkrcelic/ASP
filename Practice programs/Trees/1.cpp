#include "Stabla_template.h"

template <typename T> int BinaryTree<T>::countNodes(shared_ptr<Node<T>> &node) {
   if (node) {
      return countNodes(node->left) + countNodes(node->right) + 1;
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
   tree.insert(0);

   cout << "Num of nodes: " << tree.countNodes() << endl;
   return 0;
}