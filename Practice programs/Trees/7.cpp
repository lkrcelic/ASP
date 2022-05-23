#include "Stabla_template.h"

template <typename T>
int BinaryTree<T>::sumLevel(shared_ptr<Node<T>> &node, int level) {
   if (node) {
      if (level == 1)
         return node->item;
      else
         return sumLevel(node->left, level - 1) +
                sumLevel(node->right, level - 1);
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
   tree.insert(5);

   tree.printTree();
   cout << endl;

   cout << "Sum of a level 1: " << tree.sumLevel(1) << endl;
   cout << "Sum of a level 2: " << tree.sumLevel(2) << endl;
   cout << "Sum of a level 3: " << tree.sumLevel(3) << endl;
   cout << "Sum of a level 4: " << tree.sumLevel(4) << endl;

   return 0;
}