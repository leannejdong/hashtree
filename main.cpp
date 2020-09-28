//#include "bst.h"
#include "hashtree.h"

#include <iostream>

int main()
{
//    bst tree;
//    tree.insert(12);
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(8);
//    tree.insert(11);
//    tree.insert(15);
//    tree.insert(28);
//    tree.insert(4);
//    tree.insert(2);
//
//    std::cout << "Inorder: ";
//    tree.inorder(); // This will print all the elements in ascending order
//    std::cout << std::endl;
//
//    tree.deleteValue(12);
//    std::cout << "Inorder after deleting 12: ";
//    tree.inorder(); // This will print all the elements in ascending order
//    std::cout << std::endl;
//
//    if (tree.find(12))
//        std::cout << "Element 12 is present in the tree" << std::endl;
//    else
//        std::cout << "Element 12 is NOT present in the tree" << std::endl;

    // Implementing hash tree
    int choice, key, value, n, c;
    //   std::vector<bst> arr;
    //    init();
    do {
        cout << "Implementation of hash tree" << endl;
        cout << "MENU-: \n1. Insert an item in the hash tree"
                "\n2.Remove an item from the hash tree"
                "\n3.Check the size of the tree"
                "\n4.Display the Hash tree"
                "\n\n Please enter your choice-:";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Inserting elements in hash tree" << endl;
                cout << "Enter ket and value-:          ";
                cin >> key >> value;
                add(key, value);
                break;

            case 2:
                cout << "Deleting item from hash tree \n Enter the key to delete-:";
                cin >> key;
                del(key);
                break;

            case 3:
                n = size_of_hashTree();
                cout << "Size of hash tree is-:" << n << endl;
                break;

            case 4:
                display();
                break;

            default:
                cout << "Wrong Input" << endl;
        }
        cout << "\n Do you want to continue-: (press 1 or yes) ";
        cin >> c;

    } while(c==1);
    return 0;
}
