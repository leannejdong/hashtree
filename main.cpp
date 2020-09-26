/* Why hashing? A way of converting arbitrary data into a fixed size number
 * For secure communication, it provides a way to check that the data hasn't been changed
 * What do we need?
 * struct node: node for storing an item in a binary tree
 * struct bst: for storing a binary tree at each index of hash tree
 * struct bst *arr
 */

#include "bst.h"

#include <iostream>

int main()
{
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "Inorder: ";
    tree.inorder(); // This will print all the elements in ascending order
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "Inorder after deleting 12: ";
    tree.inorder(); // This will print all the elements in ascending order
    std::cout << std::endl;

    if (tree.find(12))
        std::cout << "Element 12 is present in the tree" << std::endl;
    else
        std::cout << "Element 12 is NOT present in the tree" << std::endl;
}
