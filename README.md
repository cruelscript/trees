# Binary Search Tree

Implementation of a template class BinarySearchTree 

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
  
  In implementation were used Not STL's queue and stack
  
# Бинарное Дерево Поиска
  
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

В имплементации были использованы Очередь и Стек не из STL
