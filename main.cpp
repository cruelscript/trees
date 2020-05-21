#include "BinaryTreeSearch.h"
#include <iostream>

int main()
{
  BinarySearchTree <int> intTree;

  intTree.insert(10);
  intTree.insert(3); 
  intTree.insert(20);
  intTree.insert(15);
  intTree.insert(30);
  intTree.insert(2);
  intTree.insert(5);
  intTree.insert(32);
  intTree.insert(22);

  std::cout << "\nPrinting intTree...\n";
  intTree.print(std::cout);

  int keyFound = intTree.iterativeSearch(15);
  std::cout << "Key " << 15 <<
    (keyFound ? " found successfully" : " not found") <<
    " in the tree\n";

  keyFound = intTree.iterativeSearch(23);
  std::cout << "Key " << 23 <<
    (keyFound ? " found successfully" : " not found") <<
    " in the tree\n";

  std::cout << "\nPrinting in order intTree...\n";
  intTree.printInOrder();

  std::cout << "\nThe number of even elements is " << intTree.getEvenElements();

  std::cout << "\nDeleting a branch (3) of the intTree...\n";
  intTree.deleteKey(3);
  std::cout << "\nDeleting a leave (32) of the intTree...\n";
  intTree.deleteKey(32);
  std::cout << "\nDeleting a root (10) of the intTree...\n";
  intTree.deleteKey(10);

  std::cout << "\nPrinting intTree...\n";
  intTree.print(std::cout);

  BinarySearchTree <int> intTreeZero;

  std::cout << "\nPrinting empty tree...\n";
  intTreeZero.print(std::cout);
  std::cout << "\nDeleting the element of the empty tree...\n";
  intTreeZero.deleteKey(5);

  std::cout << "\nThe next element after 20 in intTree is " << 
    intTree.treeSuccessor(20);
  std::cout << "\nThe height of intTree is " << 
    intTree.getHeight();
  std::cout << "\nThe number of elements in intTree is " << 
    intTree.getCount();

  
  std::cout << "\nIterative printing in order intTree...\n";
  intTree.printInOrderIterative();
  std::cout << "\nPrinting in breadth intTree...\n";
  intTree.printInBreadth();

  BinarySearchTree<int> firstTree;
  BinarySearchTree<int> secondTree;

  firstTree.insertRecursive(3);
  firstTree.insertRecursive(1);
  firstTree.insertRecursive(5);
  firstTree.insertRecursive(4);
  firstTree.insertRecursive(2);

  secondTree.insert(4);
  secondTree.insert(2);
  secondTree.insert(3);
  secondTree.insert(5);
  secondTree.insert(1);

  std::cout << "\nFirst tree is " << 
    ((firstTree.isSimilarTo(secondTree)) ? "" : "not ") << 
    "similar to the second tree.\n";

  BinarySearchTree<int> thirdTree;
  BinarySearchTree<int> fourthTree;

  thirdTree.insert(5);
  thirdTree.insert(4);
  thirdTree.insert(1);
  thirdTree.insert(3);
  thirdTree.insert(7);

  fourthTree.insert(5);
  fourthTree.insert(4);
  fourthTree.insert(3);
  fourthTree.insert(1);
  fourthTree.insert(7);

  std::cout << "\Third tree is " <<
    ((thirdTree.isSimilarTo(fourthTree)) ? "" : "not ") <<
    "similar to the fourth tree.\n";

  return 0;
}