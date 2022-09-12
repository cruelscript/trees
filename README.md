# Trees

Here are some implementations of different trees in C++ and Python. 

### General Tree

Naive implementation of a basic concept of a tree as a data structure. 

### Binary Search Tree

#### Python Implementation of a Binary Search Tree

Implemented these features: 

- All-order traversals 
- Min and Max element in a tree
- Binary Search in a tree
- Sum of all elements
- Build a reverse tree

#### C++ Implementation of a template class BinarySearchTree 

1. Node of the tree contains these elements: 
  - ```key_``` - value of the Node
  - ```left_``` - pointer to the left subtree
  - ```right_``` - pointer to the right subtree
  - ```p_``` - pointer to a predecessor (not used)
2. Node can be used only in the following class
3. private class member ```root_``` - pointer to a tree root
4. Were implemented these features: 
  - Creation of a null tree
  - Adding a new element to the tree (Itertively and Recursively)
  - Searching the element with the key value (Iteratively)
  - Searching the next element after the specified
  - Ability to get the number of the tree nodes (Recursively)
  - Ability to get the height of the tree (Recursively)
  - Memory deallocation (Recursively)
  - Deleting element from a tree, which does not cause elements be out of order 
  - Printing Node value knowing index of a Node 
  - Iterative Breadth Walk 
  - Iterative Prefix Walk
  - Method to check if trees are even
  
  In implementation were used Not STL's queue and stack
  
### C++ Бинарное Дерево Поиска
  
1. Для описания узла дерева использовать тип Node, в котором
  - ```key_``` - значение ключа узла,
  - ```left_``` - указатель на левое поддерево,
  - ```right_``` - указатель на правое поддерево,
  - ```p_``` - указатель на родителя (может не использоваться).
2. Тип Node может использоваться только в классе BinarySearchTree.
3. В классе BinarySearchTree должен быть закрытый член класса: указатель на корень дерева (```root_```).
4. Реализовать следующие возможности:
  - Создание пустого дерева
  - Добавление нового элемента в дерево (итеративно и рекурсивно)
  - Поиск элемента с заданным значением ключа (итеративно)
  - Поиск элемента, следующего за указанным
  - Определение количества узлов дерева (рекурсивно)
  - Определение высоты дерева (рекурсивно)
  - Освобождение памяти (рекурсивно)
  - Удаление элемента из дерева, не нарушающее порядка элементов
  - Вывод информации узла с заданным номером
  - Итеративный метод обхода двоичного дерева по уровням (в ширину). В реализации использован класс очередь
  - Итеративный метод обхода двоичного дерева слева направо (префиксный). В реализации использовать класс стек. 
  - Метод, определяющий являются ли деревья похожими (назовем деревья похожими, если они содержат одинаковые наборы ключей)

В имплементации были использованы Очередь и Стек не из STL

### Trie

Trie is a prefix tree. Python implementation.

### Heap

Heap is a tree where elements are in ascending or descending order relative to node's children. 

Here is Max heap implementation. Heap rebuilds itself everytime it has been added or removed an element, 
thus a max element will always be on top.