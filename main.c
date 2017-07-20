//
//  main.c
//  IntervalBinarySearchTree
//


//
//  main.c
//  INTERVAL(BST)
//
//  Created by Aggelos Kappos on 11/1/14.
//  Copyright (c) 2014 Aggelos Kappos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "intervalbst.h"

struct node *searchinterval(struct node *x,struct node *j);
struct node *treeMinimum(struct node *x);
struct node *searchinterval(struct node *x,struct node *j);
struct node* insert(struct node *root, int key,int key2);
void inorder(struct node *root);
struct node* Delete(struct node *root, int key);


int main(void)
{
    /*Let us create following BST
     50
     /     \
     30      70
     /  \    /  \
     20   40  60   80*/
    
    
    printf("\nThe low elements of the tree is:\n");
    
    struct node *root = NULL;
    root= insert(root, 50,80);
    root =insert(root, 30,40);
    root =insert(root, 20,34);
    root =insert(root, 40,42);
    root =insert(root, 70,81);
    root =insert(root, 60,71);
    root =insert(root, 80,89);
    
    // print inorder traversal of the BST
    printf("\n The inorder traversal of Bstree is:   ");
    inorder(root);
    
    
    root=Delete(root, 80);
    root=Delete(root,40);
    printf("\n 2 Nodes of the tree is deleted, and");
    
    printf("\n after deletion the inorder of BST is:");
    inorder(root);
    
}
