#include "Stabla_template.h"

template <typename T>
void BinaryTree<T>::nthValue(shared_ptr<Node<T>> &node, int n, T &item,
                             int &curr) {
   if (node) {
      if (node->right)
         nthValue(node->right, n, item, curr);
      ++curr;
      if (n == curr)
         item = node->item;
      if (node->left)
         nthValue(node->left, n, item, curr);
   }
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

   cout << "Second highest value: " << tree.nthValue(2) << endl;

   return 0;
}