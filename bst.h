//
// Created by leanne on 9/26/20.
//

#ifndef HASHTREE_BST_H
#define HASHTREE_BST_H


#include <iostream>
#include <memory>

using std::unique_ptr;
using std::make_unique;


struct node
{
    int data;
    unique_ptr<node> left, right;
};

struct bst
{
    unique_ptr<node> root;

    node *find(int value)
    {
        return find_impl(root.get(), value);
    }

private:
    node *find_impl(node *current, int value)
    {
        if (!current)
        {
            std::cout << std::endl;
            return nullptr;
        }
        if (current->data == value)
        {
            std::cout << "Found " << value << std::endl;
            return current;
        }
        if (value < current->data) // Value will be in the left subtree
        {
            std::cout << "Going left from " << current->data << ", ";
            return find_impl(current->left.get(), value);
        }
        // Value will be in the right subtree
        std::cout << "Going right from " << current->data << ", ";
        return find_impl(current->right.get(), value);
    }

public:
    void insert(int value)
    {
        if (!root)
            root = make_unique<node>(node{value, nullptr, nullptr});
        else
            insert_impl(root.get(), value);
    }

private:
    void insert_impl(node *current, int value)
    {
        if (value < current->data)
        {
            if (!current->left)
                current->left = make_unique<node>(node{value, nullptr, nullptr});
            else
                insert_impl(current->left.get(), value);
        }
        else
        {
            if (!current->right)
                current->right = make_unique<node>(node{value, nullptr, nullptr});
            else
                insert_impl(current->right.get(), value);
        }
    }

public:
    void inorder()
    {
        inorder_impl(root.get());
    }

private:
    void inorder_impl(node *start)
    {
        if (!start)
            return;
        inorder_impl(start->left.get());       // Visit the left sub-tree
        std::cout << start->data << " "; // Print out the current node
        inorder_impl(start->right.get());      // Visit the right sub-tree
    }

public:
    node *successor(node *start)
    {
        auto current = start->right.get();
        while (current && current->left)
            current = current->left.get();
        return current;
    }

    void deleteValue(int value)
    {
        root = delete_impl(std::move(root), value);
    }

private:
    unique_ptr<node> delete_impl(unique_ptr<node> start, int value)
    {
        if (!start)
            return nullptr;
        if (value < start->data)
            start->left = delete_impl(std::move(start->left), value);
        else if (value > start->data)
            start->right = delete_impl(std::move(start->right), value);
        else
        {
            if (!start->left) // Either both children are absent or only left child is absent
            {
                return std::move(start->right);
            }
            if (!start->right) // Only right child is absent
            {
                return std::move(start->left);
            }

            auto succNode = successor(start.get());
            start->data = succNode->data;
            // Delete the successor from right subtree, since it will always be in the right subtree
            start->right = delete_impl(std::move(start->right), succNode->data);
        }
        return start;
    }
};


#endif //HASHTREE_BST_H
