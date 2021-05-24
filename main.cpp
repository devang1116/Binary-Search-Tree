//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by Devang Papinwar on 05/03/21.
//

#include <iostream>
using namespace std;

struct Person
{
    int data;
    Person *left;
    Person *right;
};

void inOrder(Person* parent)
{
    struct Person* node = parent;
    if( node == NULL)
        return;
    inOrder(node->left) ;
    cout << " Node : " << node->data << endl;
    inOrder(node->right) ;
}

struct Person *newNode(int data)
{
    struct Person* temp=(struct Person*)malloc(sizeof(struct Person));
    temp->data = data;
    temp->left = NULL;
    temp->right =NULL;
    return temp;
}

struct Person *left(Person *root)
{
    if( root == NULL )
    {
        cout << " NO NODE " ;
        return NULL;
    }
    else
    {
        return root->left;
    }
}

struct Person *right(Person *root)
{
    if( root == NULL )
    {
        cout << " NO NODE " ;
        return NULL;
    }
    else
    {
        return root->right;
    }
}

int findMin(Person *root)
{
    struct Person* ro = root;
    if( ro == NULL )
    {
        cout << " TREE EMPTY ";
        return NULL;
    }
    while( ro->left != NULL )
    {
        ro = ro->left;
    }
    //cout << " MIN DATA : " << ro->data;
    return ro->data;
}

struct Person *findMax(Person *root)
{
    struct Person* ro = root;
    if( root == NULL )
    {
        cout << " TREE EMPTY ";
        return NULL;
    }
    while( ro->right != NULL )
    {
        ro = ro->right;
    }
    cout << " MAX DATA : " << ro->data;
    return ro;
}

void search(Person *root , int data)
{
    struct Person* node = root;
    if( root == NULL )
        cout << " TREE EMPTY ";
    if( data == root->data )
        cout << " DATA FOUND " << root->data;
    else if( root->left != NULL)
    {
        search(root->left , data) ;
    }
    else if( root->right != NULL)
    {
        search(root->right , data) ;
    }
    else{
        cout << " NOT FOUND ";
    }
}

void getChild(Person *root)
{
    if( root == NULL )
        return;
    if( root->left || root->right )
    {
        cout << " PARENT NODE : " << root->data;
        if( root->left )
            cout << " LEFT CHILD : " << root->left->data ;
        if( root->right )
            cout << " RIGHT CHILD : " << root->right->data << endl;
    }
    getChild(root->left);
    getChild(root->right);
}

void leafNode(Person *root)
{
    struct Person* node = root;
    if( node == NULL )
        return;
    if( node->left == NULL && node->right == NULL )
        cout << " LEAF NODE : " << node->data << endl;
    if( node->left != NULL )
        leafNode(node->left) ;
    if( node->right != NULL )
        leafNode(node->right) ;
}

void insertNode(Person* root , int data)
{
    struct Person* temp = root;
    if(data == temp->data)
    {
        return ;
    }
    if(data < temp->data)
    {
        if(temp->left == NULL)
        {
            temp->left = newNode(data);
        }
        else
        {
            insertNode( temp->left , data );
        }
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = newNode(data);
        }
        else
        {
            insertNode( temp->right , data);
        }
    }
}

struct Person *removeNode(Person *root , int data)
{
    if( root == NULL )
        return root;
    if( data < root->data )
        root->left = removeNode( root->left , data );
    else if( data > root->data )
        root->right = removeNode( root->right, data );
    else
    {
        if( root->left == NULL )
            return root->right ;
        else if( root->right == NULL )
            return root->left;
        else{
        root->data = findMin(root->right);
        root->right = removeNode(root->right, root->data);
        }
    }
    return root;
}

void del(Person *root , int data)
{
    removeNode(root, data);
}

int main(int argc, const char * argv[])
{
    struct Person* root = new Person();
    root->data = 10;
    root->left = NULL;
    root->right = NULL;
    insertNode(root,8);
    insertNode(root,17);
    insertNode(root,5);
    insertNode(root,9);
    //insertNode(root);
    /**/
    //
    //findMin(root);
    //findMax(root);
    //search(root , 12);
    //getChild(root);
    //leafNode(root);
    del( root , 10 );
    inOrder(root);
    //cout << " ROOT 1 : " << root->data;
    //cout << " ROOT LEFT : " << root->left->data;
    //cout << " ROOT RIGHT : " << root->right->data;
    //cout << " ROOT LEFT LEFT : " << root->left->left->data;
    //cout << " ROOT LEFT RIGHT : " << root->left->right->data;
}
