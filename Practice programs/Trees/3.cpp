#include "Stabla_template.h"

template <typename T>
int BinaryTree<T>::countLevel(shared_ptr<Node<T>> &node, int level) {
   if (node && level >= 1) {
      if (level == 1)
         return 1;
      else
         return countLevel(node->left, level - 1) +
                countLevel(node->right, level - 1);
   } else
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
   tree.insert(0);

   cout << "Num of nodes at 3rd level: " << tree.countLevel(3) << endl;
   cout << "Num of nodes at 2rd level: " << tree.countLevel(2) << endl;
   cout << "Num of nodes at 1rd level: " << tree.countLevel(1) << endl;
   cout << "Num of nodes at 4rd level: " << tree.countLevel(4) << endl;

   return 0;
}