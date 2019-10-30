#include "b_tree.h"

bool Tree::addLeft(ptr node)
{
    this->left = node;
    return true;
}

bool Tree::addRight(ptr node)
{
    this->right = node;
    return true;
}
