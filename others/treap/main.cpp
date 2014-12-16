#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct treapnode;
typedef struct treapnode *treap;

struct treapnode
{
    int key,fix;
    treap left,right;
};

treap nullnode,root;

void initialize()
{
    nullnode = new treapnode;
    nullnode->left = nullnode->right = nullnode;
    root=nullnode;
}

void sigrotl(treap& k1)
{
    treap k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

void sigrotr(treap& k1)
{
    treap k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

void insert(treap& t,int x)
{
    if(t == nullnode)
    {
        t = new treapnode;
        t->left = t->right = nullnode;
        t->key = x;
        t->fix = rand();
    }
    else
    if(t->key == x)return;
    else
    if(x < t->key)
    {
        insert(t->left,x);
        if(t->left->fix > t->fix)sigrotr(t);
    }
    else
    {
        insert(t->right,x);
        if(t->right->fix > t->fix)sigrotl(t);
    }
}

void remove(treap& t,int x)
{
    if(t == nullnode)return;
    if(x > t->key)remove(t->right,x);
    else if(x < t->key)remove(t->left,x);
    else
    {
        if(t->left == nullnode && t->right == nullnode)
        {
            delete t;
            t=nullnode;
        }
        else if(t->left == nullnode)
        {
            treap tmp = t;
            t = t->right;
            delete tmp;
        }
        else if(t->right == nullnode)
        {
            treap tmp = t;
            t = t->left;
            delete tmp;
        }
        else
        if(t->left->fix < t->right->fix)
        {
            sigrotl(t);
            remove(t->left,x);
        }
        else
        {
            sigrotr(t);
            remove(t->right,x);
        }
    }
}

void list(treap t)
{
    if(t == nullnode)return;cout << t->key << endl;
    list(t->left);

    list(t->right);
}

int main()
{
    initialize();
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    list(root);
    system("pause");
}
