/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <cstdlib>
#include "general.h"

struct Node{
  int element;
  Bst left;
  Bst right;
};


Bst create_node(Bst* bst, int value){
  Bst newNode = (Bst)malloc(sizeof(Node));
  newNode->element=value;
  newNode->right=0;
  newNode->left=0;
  return newNode;
}

Bst new_bst()
{
  Bst bst = 0;
  return bst;
}

void delete_bst(Bst bst)
{
  if(bst != 0)
  {
      delete_bst(bst->left);
      delete_bst(bst->right);
      sfree(bst);
  }
}

/**
*** @return The depth of the BST
*/
int get_depth(Bst bst)
{
  if(bst==0)
  {
    return 0;
  }
  else
  {
    int ldepth=get_depth(bst->left);
    int rdepth=get_depth(bst->right);

    if(ldepth>rdepth)
    {
      return ldepth+1;
    }
    else
    {
      return rdepth+1;
    }
  }
}

/**
*** Adds a value to the BST
*/
void add(Bst* bst, int value)
{
  if (*bst==0)
  {
    *bst = create_node(&(*bst), value);
  }
  else if(value<=(*bst)->element)
  {
    if((*bst)->left == 0)
    {
      (*bst)->left=create_node(&(*bst), value);
    }
    else
    {
      add(&(*bst)->left, value);
    }
  }
  else if(value>(*bst)->element)
  {
    if((*bst)->right == 0)
    {
      (*bst)->right=create_node(&(*bst), value);
    }
    else
    {
      add(&(*bst)->right, value);
    }
  }
}

/**
*** @return The value of the root element of the BST
*/
int root_value(Bst bst)
{
  return bst->element;
}

/**
*** @return The left subtree of the BST
*/
Bst left_subtree(Bst root)
{
  return root->left;
}

/**
*** @return The right subtree of the BST
*/
Bst right_subtree(Bst root)
{
  return root->right;
}

/**
*** Traverses the BST depth first by first returning the root, then traversing the left
*** subtree, then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_pre_order(Bst bst, int *elements, int start)
{
  if(bst != 0)
  {
      elements[start] = bst->element;
      if(get_depth(bst) > 0)
      {
        start+=1;
        start = traverse_pre_order(bst->left, elements, start);
        start = traverse_pre_order(bst->right, elements, start);
      }
  }
  return start;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then adding the root,
*** then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_in_order(Bst bst, int *elements, int start)
{
  if(bst != 0)
  {
    if(bst->left != 0)
    {
      start = traverse_in_order(bst->left, elements, start);
    }
    elements[start] = bst->element;
    start+=1;
    if(bst->right != 0)
    {
      start = traverse_in_order(bst->right, elements, start);
    }
  }
  return start;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then traversing the right
*** subtree and finally adding the root.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_post_order(Bst bst, int *elements, int start)
{
  if(bst != 0)
  {
      if(bst->left != 0)
      {
        start = traverse_post_order(bst->left, elements, start);
      }
      if(bst->right != 0)
      {
        start = traverse_post_order(bst->right, elements, start);
      }
      elements[start] = bst->element;
      start+=1;
  }
  return start;
}

/**
*** Checks whether two trees are equal
*** @param bst1 First bst
*** @param bst2 Second bst
*** @return true if bst1 and bst2 are equal, false otherwise
*/
bool are_equal(Bst bst1, Bst bst2)
{
  if(bst1 == 0)
  {
    return bst2 == 0;
  }
  else if(get_depth(bst1) == get_depth(bst2))
  {
      if(bst1->element == bst2->element)
      {
        return are_equal(bst1->left, bst2->left) && are_equal(bst1->right, bst2->right);
      }
  }
  return false;
}

/**
*** Calculates the longest branch in the tree. If two branches are equally long
*** the left branch is taken.
*** @param bst Bst which longest branch should be found
*** @return A tree where each node has only one child equal to the longest
*** branch of bst
*/
void most_left_longest_branch(Bst bst, Bst* branch)
{

}

/**
*** Gets the number of non-empty subtrees of a tree
*** @param bst The tree which number of subtrees to get
*** @return The number of non-empty subtrees
*/
int get_number_of_subtrees(Bst bst)
{
  return 0;
}
