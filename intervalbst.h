//
//  intervalbst.h
//  IntervalBinarySearchTree
//
//  Created by Angelos Kappos on 20/7/17.
//  Copyright © 2017 Angelos Kappos. All rights reserved.
//

#ifndef intervalbst_h
#define intervalbst_h

struct node
{
    struct node *i;
    int max,low,high;
    int key,key2;
    struct node *left;
    struct node *right;
    struct node *parent;
    
};


struct node *searchinterval(struct node *x,struct node *j)
{
    struct node *root;
    x=root;
    while (x!=NULL && (j->key>=x->high|| j->high<= x->key)) // x!=null and i doesnot overlap x.int
    {
        if(x->left !=NULL && x->left->max >= j->key )
        {x= x->left;}
        else
        {x=x->right;}
    }
    return x;
}


struct node *treeMinimum(struct node *x)
{
    while (x->right!=NULL)
    {
        x=x->right;
    }
    return x;
}

struct node* insert(struct node *root, int key,int key2)
{
    
    struct node *y = NULL;
    struct node *x;
    struct node *z;
    z=(struct node*)malloc(sizeof(struct node));
    z->left=z->right=z->parent=NULL;
    z->key=key;
    key=z->low;
    z->key2=key2;
    z->max=z->high;
    x=(struct node *)malloc(sizeof(struct node));
    x=root;
    while(x != NULL)
    {
        y=x;
        if (key<x->key)
        {
            if (x->max<key2)
            {
                x->max=key2;
            }
            x=x->left;
        }
        else {
            if (x->max<key2)
            {
                x->max=key2;
            }
            x=x->right;
        }
    }
    z->parent=y;
    if (y == NULL)
    {
        root=z;
        root->max=z->key2;
    }
    else if (z->key<y->key)
    {
        y->left=z;
        if(z->max>y->max)
        {
            y->max=z->key2;
        }
        if(y->max>root->max)
        {root->max=y->key2;}
    }
    else
    {
        y->right=z;
        if(z->max>y->max)
        {
            y->max=z->key2;
        }
        if(y->max>root->max)
        {root->max=y->key2;}
    }
    
    printf("%d \n", z->key);
    return root;
    
}


//voithitiki sunartisi wste na dinei ton inorder traversal tou BSTree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d,%d] max = %d \n", root->key,root->key2,root->max);
        inorder(root->right);
    }
}


struct node* Delete(struct node *root, int key)
{
    if(root == NULL) return root;                                       //an dentro keno,epistrefei riza.
    else if(key < root->key) root->left = Delete(root->left,key);    //an data pou psaxnoume < data->root
    //pigainei aristero upodentro kai delete
    else if (key > root->key) root->right = Delete(root->right,key); //an data pou psaxnoume > data->root
    //pigainei dexi upodentro kai delete
    
    else {
        
        if(root->left == NULL && root->right == NULL)                   // kanena paidi
        {
            free (root);
            root = NULL;
        }
        
        else if(root->left == NULL)// 1 paidi
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free (temp);
        }
        
        else //2paidia
        {
            struct node *temp = treeMinimum(root->right);
            root->key = temp->key;
            root->right = Delete(root->right,temp->key);
        }
    }
    return root;
}

#endif /* intervalbst_h */
