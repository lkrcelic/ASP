#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Node {
   int item;
   shared_ptr<Node<T>> left;
   shared_ptr<Node<T>> right;
   Node(const T &newitem) : item(newitem), left(nullptr), right(nullptr) {}
   ~Node() { std::cout << "Destructor (" << item << ")\n"; }
};

template <typename T> class BinaryTree {
 private:
   shared_ptr<Node<T>> root = nullptr;
   // ZADATCI
   int countNodes(shared_ptr<Node<T>> &);
   int inorder2(shared_ptr<Node<T>> &);
   int countLevel(shared_ptr<Node<T>> &, int);
   void nthValue(shared_ptr<Node<T>> &, int, T &, int &);
   int changeValues(shared_ptr<Node<T>> &);
   int sumLevel(shared_ptr<Node<T>> &, int);
   // ZADATCI

 public:
   // ZADATCI
   int countNodes() { return countNodes(root); }
   int inorder2() { return inorder2(root); }
   int countLevel(int level) { return countLevel(root, level); }
   // cijeli 4.template <typename T>
   void freeAllNodes() { root = nullptr; }
   T nthValue(int n) {
      T item;
      int curr = 0;
      nthValue(root, n, item, curr);
      return item;
   }
   void changeValues() { changeValues(root); }
   int sumLevel(int level) { return sumLevel(root, level); }
   // ZADATCI
   bool isEmpty() { return root == nullptr; }
   void insert(const T &newItem) { insert(root, newItem); }
   bool remove(const T &item) { return remove(root, item); }
   bool search(const T &item) { return search(root, item); }
   bool isBalanced() { return isBalanced(root); }
   int height() { return height(root); }
   void print_inorder() { print_inorder(root); }
   void print_preorder() { print_preorder(root); }
   void print_postorder() { print_postorder(root); }
   void printTree() { printTree(root, 0); }
   int sumTree() { return sumTree(root); }

   int height(shared_ptr<Node<T>> &node) {
      if (node) {
         int heightLeft = height(node->left);
         int heightRight = height(node->right);
         return max(heightLeft, heightRight) + 1;
      } else
         return 0;
   }

   bool isBalanced(shared_ptr<Node<T>> &node) {
      if (node) {
         int heightLeft = height(node->left);
         int heightRight = height(node->right);
         return (std::abs(heightLeft - heightRight) <= 1 &&
                 isBalanced(node->left) && isBalanced(node->right));
      }
      return true;
   }

   void insert(shared_ptr<Node<T>> &root, const T &newItem) {
      if (root) {
         if (root->item > newItem)
            insert(root->left, newItem);
         else if (root->item < newItem)
            insert(root->right, newItem);
         else {
            cout << "Stablo vec sadrzi element" << endl;
            return;
         }
      } else
         root = make_shared<Node<T>>(newItem);
   }

   bool search(shared_ptr<Node<T>> &root, const T &item) {
      if (root) {
         if (root->item > item)
            search(root->left, item);
         else if (root->item < item)
            search(root->right, item);
         else {
            return true;
         }
      } else
         return false;
   }

   void print_preorder(shared_ptr<Node<T>> &root) {
      if (root == nullptr)
         return;
      cout << root->item << " ";
      print_preorder(root->left);
      print_preorder(root->right);
   }
   void print_inorder(shared_ptr<Node<T>> &root) {
      if (root == nullptr)
         return;
      print_inorder(root->left);
      cout << root->item << " ";
      print_inorder(root->right);
   }

   void print_postorder(shared_ptr<Node<T>> &root) {
      if (root == nullptr)
         return;
      print_postorder(root->left);
      print_postorder(root->right);
      cout << root->item << " ";
   }

   int sumTree(shared_ptr<Node<T>> &node) {
      if (node == nullptr) {
         return 0;
      }
      T sum_l = sum_tree(node->left);
      T sum_r = sum_tree(node->right);
      T rez = sum_l + sum_r + node->item;
      return rez;
   }
   void printTree(shared_ptr<Node<T>> &node, int level) {
      if (node) {
         printTree(node->right, level + 1);
         string spaces(level * 2, ' ');
         cout << spaces << node->item << "\n";
         printTree(node->left, level + 1);
      }
      return;
   }
   bool remove(shared_ptr<Node<T>> &node, const T &item) {
      if (node) {
         if (node->item < item) {
            return remove(node->right, item);
         } else if (node->item > item) {
            return remove(node->left, item);
         } else {              // found item
            if (!node->left) { // no left subtree
               node = node->right;
            } else if (!node->right) { // no right subtree
               node = node->left;
            } else {
               shared_ptr<Node<T>> tmp = node->left, prev = nullptr;
               while (
                   tmp->right) { // find the rightmost child in the left subtree
                  prev = tmp;
                  tmp = tmp->right;
               }
               node->item = tmp->item;
               if (prev)
                  prev->right = tmp->left;
               else
                  node->left = tmp->left;
            }
            return true;
         }
      }
      return false;
   }
};
