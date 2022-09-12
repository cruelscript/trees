#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

#include "StackList.hpp"
#include "QueueList.hpp"

template <class T>
class BinarySearchTree
{
private:
  class Node
  {
  public:
    T key_;
    Node* left_;
    Node* right_;
    Node* p_;
    explicit Node(const T& key, Node* left = nullptr, Node* right = nullptr,
      Node* p = nullptr) :
        key_(key), left_(left), right_(right), p_(p)
    {}
  };
  Node* root_;

public:

  BinarySearchTree() : root_(nullptr)
  {}

  virtual ~BinarySearchTree()
  {
    deleteSubTree(root_);
  }

  void print(std::ostream& out)const
  {
    printNode(out, root_);
    out << '\n';
  }

  bool iterativeSearch(const T& key)const
  {
    return iterativeSearchNode(key);
  }

  int getEvenElements()
  {
    return getEvenNodeElements(root_);
  }

  void printInOrder()const
  {
    inOrderWalk(root_);
  }

  void printInOrderIterative()const
  {
    inOrderWalkIterative(root_);
  }

  void printInBreadth()const
  {
    breadthWalk(root_);
  }

  void insertRecursive(const T& key)
  {
    insertRecursiveNode(root_, key);
  }
  bool insert(const T& key)
  {
    if (!root_)
    {
      root_ = new Node(key);
      return true;
    }

    Node* temp = root_;
    Node* current = nullptr;

    while (temp)
    {
      current = temp;

      if (key < temp->key_)
      {
        temp = temp->left_;
      }
      else if (key > temp->key_)
      {
        temp = temp->right_;
      }
    }
    if (key < current->key_)
    {
      current->left_ = new Node(key);
      current->left_->p_ = current;
      return true;
    }
    else if (key > current->key_)
    {
      current->right_ = new Node(key);
      current->right_->p_ = current;
      return true;
    }
    return false;
  }

  void deleteKey(const T& key)
  {
    if (!root_)
      return;

    Node* temp = root_;
    Node* parent = nullptr;

    while (temp->key_ != key)
    {
      parent = temp;
      if (key < temp->key_)
      {
        temp = temp->left_;
      }
      else temp = temp->right_;
    }

    if (!temp->left_ && !temp->right_)      // узел без потомков
    {
      if (!parent)
      {

        delete temp;
        root_ = nullptr;
      }
      else if (parent->left_ == temp)
      {
        delete temp;
        parent->left_ = nullptr;
      }
      else if (parent->right_ == temp)
      {
        delete temp;
        parent->right_ = nullptr;
      }
    }
    else if (temp->left_ && !temp->right_) // один левый потомок
    {
      temp->key_ = temp->left_->key_;
      delete temp->left_;
      temp->left_ = nullptr;
    }
    else if (!temp->left_ && temp->right_) // один правый потомок
    {
      temp->key_ = temp->right_->key_;
      delete temp->right_;
      temp->right_ = nullptr;
    }
    else if (temp->left_ && temp->right_) // оба потомка
    {
      parent = temp->right_;              // тут и далее по смыслу parent есть successor

      parent = treeMin(parent);

      temp->key_ = parent->key_;

      if (parent->p_ == temp)
      {
        delete parent;
        temp->right_ = nullptr;
      }
      else
      {
        parent = parent->p_;
        delete parent->left_;
        parent->left_ = nullptr;
      }
    }
  }

  Node* treeMin(Node* node)const
  {
    while (node->left_)
      node = node->left_;

    return node;
  }

  Node* treeMax(Node* node)const
  {
    while (node->right_)
      node = node->right_;

    return node;
  }

  T& treeSuccessor(const T& key)const
  {
    return treeNodeSuccessor(iterativeSearchNode(key))->key_;
  }

  T& treePredecessor(const T& key)const
  {
    return treeNodePredecessor(iterativeSearchNode(key))->key_;
  }

  int getCount()const
  {
    return getCountSubTree(this->root_);
  }
  int getHeight()const
  {
    return getHeightSubTree(this->root_);
  }

  bool isSimilarTo(const BinarySearchTree<T>& thatTree)
  {
    if(!root_ && !thatTree.root_)
    {
      std::cout << "\nTrees are empty\n";
      return true;
    }
    if((!root_ && thatTree.root_) || (root_ && !thatTree.root_))
    {
      std::cout << "\nOne of the trees is empty\n";
      return false;
    }

    StackList<Node*> thisStack;
    StackList<Node*> thatStack;
    Node* thisTemp = this->root_;
    Node* thatTemp = thatTree.root_;

    while ((thisTemp && thatTemp) || !thisStack.isEmpty() || !thatStack.isEmpty())
    {
      while(thisTemp)
      {
        thisStack.push(thisTemp);
        thisTemp = thisTemp->left_;
      }

      while(thatTemp)
      {
        thatStack.push(thatTemp);
        thatTemp = thatTemp->left_;
      }

      thisTemp = thisStack.pop();
      thatTemp = thatStack.pop();

      if (thisTemp->key_ != thatTemp->key_)
        return false;

      thisTemp = thisTemp->right_;
      thatTemp = thatTemp->right_;
    }
    return thisStack.isEmpty() && thatStack.isEmpty();
  }
private:

  int getEvenNodeElements(Node* node)
  {
    if (!node)
      return 0;

    return ((node->key_ % 2 == 0) ? 1 : 0) +
      getEvenNodeElements(node->left_) + getEvenNodeElements(node->right_);
  }

  Node* iterativeSearchNode(const T& key)const
  {
    Node* temp = root_;

    while (temp && key != temp->key_)
    {
      if (key < temp->key_)
        temp = temp->left_;
      else temp = temp->right_;
    }
    return temp;
  }

  Node* treeNodeSuccessor(Node* node)const
  {
    if (node->right_)
    {
      return treeMin(node->right_);
    }
    Node* temp = node->p_;
    while (temp && (node == temp->right_))
    {
      node = temp;
      temp = temp->p_;
    }
    return temp;
  }

  Node* treeNodePredecessor(Node* node)const
  {
    if(node->left_)
    {
      return treeMax(node->left_);
    }
    Node* temp = node->p_;
    while(temp && (node == temp->left_))
    {
      node = temp;
      temp = temp->p_;
    }
    return temp;
  }

  void insertRecursiveNode(Node* node, const T& key)
  {
    if (!root_)
    {
      root_ = new Node(key);
    }
    else
    {
      Node* temp = node;

      if (!node)
        temp = root_;

      if (key > node->key_)
      {
        if (temp->right_)
          insertRecursiveNode(temp->right_, key);
        else temp->right_ = new Node(key);
      }
      else if (key < node->key_)
      {
        if (temp->left_)
          insertRecursiveNode(temp->left_, key);
        else temp->left_ = new Node(key);
      }
    }
  }

  void deleteSubTree(Node* node)const
  {
    if (node)
    {
      deleteSubTree(node->left_);
      deleteSubTree(node->right_);

      delete node;
      node = nullptr;
    }
  }

  int getCountSubTree(Node* node)const
  {
    return node ? (1 + getCountSubTree(node->left_) +
      getCountSubTree(node->right_)) : 0;
  }

  int getHeightSubTree(Node* node)const
  {
    if (!node)
      return 0;

    int left = getHeightSubTree(node->left_);
    int right = getHeightSubTree(node->right_);

    return (left > right ? left : right) + 1;
  }

  void printNode(std::ostream& out, Node* root)const
  {
    out << '(';
    if (root)
    {
      out << root->key_;
      printNode(out, root->left_);
      printNode(out, root->right_);
    }
    out << ')';
  }

  void inOrderWalk(Node* node)const
  {
    if (node)
    {
      inOrderWalk(node->left_);
      std::cout << node->key_ << " ";
      inOrderWalk(node->right_);
    }
  }

  void inOrderWalkIterative(Node* node)const
  {
    StackList<Node*> stack;
    Node* temp = node;

    while(temp || !stack.isEmpty())
    {
      if(temp)
      {
        stack.push(temp);
        temp = temp->left_;
      }
      else
      {
        temp = stack.pop();
        std::cout << temp->key_ << " ";
        temp = temp->right_;
      }
    }
  }

  void breadthWalk(Node* node)const
  {
    QueueList<Node*> queue;
    queue.enQueue(node);

    while(!queue.isEmpty())
    {
      Node* temp = queue.deQueue();
      std::cout << temp->key_ << " ";
      if (temp->left_)
        queue.enQueue(temp->left_);
      if (temp->right_)
        queue.enQueue(temp->right_);
    }
  }
};
#endif
