#ifndef HASHTREE_HASHTREE_H
#define HASHTREE_HASHTREE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;
int maxim = 10; // determines the max capacity of the hash tree
int size_tree = 0; // determines the number of elements present in hash tree

struct node {
    int key, value;
    unique_ptr<node> left, right;
};

struct bst {
    unique_ptr<node> root; // root pointing to the root of binary tree
};

//bst *arr;
std::vector<bst> arr;

// void insert(node *tree, unique_ptr<node> item);
// node *find(node *tree, int key);
// unique_ptr<node> deleteValue(unique_ptr<node> tree, int key);
// void display_tree(node *tree);
/* this function inserts the newly created node in the existing Binary Tree */
void insert(node *tree, unique_ptr<node> item)
{

    if (item->key < tree->key)

    {
        if (tree->left == nullptr)
        {
            tree->left = std::move(item);
            return;
        }
        else
        {
            insert(tree->left.get(), std::move(item));
            return;
        }
    }

    else if (item->key > tree->key)
    {
        if (tree->right == nullptr)
        {

            tree->right = std::move(item);

            return;

        }

        else
        {
            insert(tree->right.get(), std::move(item));
            return;
        }
    }
}

node *find(node *tree, int key)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    if (tree->key == key)
    {
        return tree;
    }
    else if (key < tree->key)
    {
        return find(tree->left.get(), key);
    }
    else
    {
        return find(tree->right.get(), key);
    }

}


unique_ptr<node> deleteValue(unique_ptr<node> tree, int key)

{

    if (tree == nullptr)

    {

        return nullptr;

    }

    if (key < tree->key)

    {

        tree->left = deleteValue(std::move(tree->left), key);

        return tree;

    }

    else if (key > tree->key)

    {

        tree->right = deleteValue(std::move(tree->right), key);

        return tree;

    }

    else {

        /* reached the node */

        if (tree->left == nullptr  &&  tree->right == nullptr)

        {

            size_tree--;

            return std::move(tree->left);

        }

        else if (tree->left != NULL  &&  tree->right == NULL)

        {

            size_tree--;

            return std::move(tree->left);

        }

        else if (tree->left == NULL  &&  tree->right != NULL)

        {

            size_tree--;

            return std::move(tree->right);

        }

        else {

            node *left_one = tree->left.get();



            while (left_one->right != nullptr)

            {

                left_one = left_one->right.get();

            }



            tree->key = left_one->key;

            tree->value = left_one->value;

            tree->left = deleteValue(std::move(tree->left), tree->key);

            return tree;

        }

    }

}

/* displays content of binary tree of particular index */

void display_tree(node *tree)

{

    if (tree == nullptr)

    {

        return;

    }

    cout << tree->key << " and " << tree->value << "   ";



    if (tree->left != nullptr)

    {

        display_tree(tree->left.get());

    }

    if (tree->right != nullptr)

    {

        display_tree(tree->right.get());

    }

}


/* displays the content of hash Tree */

void display()
{
    int i = 0;
    for(i = 0; i < maxim; i++)
    {
        node *tree = arr[i].root.get();

        if (tree == nullptr)

        {

            cout << "arr[" << i << "] has no elements" << endl;

        }

        else

        {

            cout << "arr[" << i << "] has elements" << endl;

            display_tree(tree);

        }

    }

}

// create an index corresponding to every given key
int hashcode(int key)
{
    return (key % maxim);
}

void add(int key, int value)
{
    int index = hashcode(key);
    // node *tree = static_cast<node *>(arr[index].root.get()); // extracting binary tree at the given index
    node *tree = arr[index].root.get();
    unique_ptr<node> new_item = make_unique<node>();
    // unique_ptr<node> new_item(new node)
    new_item->key = key;
    new_item->value = value;
    new_item->left = nullptr;
    new_item->right = nullptr;

    if (tree == nullptr)
    {
        // absence of binary tree at a given index of Hash Tree
        cout << " Inserting " << key << " and " << value << endl;
        arr[index].root = std::move(new_item);
        size_tree++;
    }
    else {
        // a binary tree is present at a given index of hash tree
        node *temp = find(tree, key);
        if (temp == nullptr)
        {
            // key not found in existing binary tree
            // adding the key in existing binary tree
            cout << "Inserting " << key << " and " << value << endl;
            insert(tree, std::move(new_item));
            size_tree++;
        }
        else {
            // key already present in existing binary tree
            // updating the value of already existing key
            temp->value = value;
        }
    }
}

/* for initializing the hash Tree */

void init()
{
    int i = 0;
    for(i = 0; i < maxim; i++)
    {
        arr[i].root = nullptr;
    }
}



/* returns the size of hash Tree */

int size_of_hashTree()
{
    return size_tree;
}



/* to del a key from hash Tree */
void del(int key)
{
    int index = hashcode(key);

    if (arr[index].root == nullptr)
    {
        cout << key << " Key not present" << endl;
    }
    else
    {
        struct node *temp = find(arr[index].root.get(), key);

        if (temp == nullptr)
        {
            cout << key << " is not present";
        }
        else
        {
            arr[index].root = deleteValue(std::move(arr[index].root), key);

            cout << key << " has been removed form the hash tree" << endl;
        }
    }
}

#endif//HASHTREE_HASHTREE_H