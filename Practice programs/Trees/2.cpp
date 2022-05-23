#include "Stabla_template.h"

template <typename T> int BinaryTree<T>::inorder2(shared_ptr<Node<T>> &node) {
   if (node) {
      int rez;
      rez = inorder2(node->left);
      cout << node->item << " ";
      rez += inorder2(node->right);
      return rez + 1;
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

   int num = tree.inorder2();
   cout << endl;
   cout << "Num of nodes: " << num << endl;
   return 0;
}