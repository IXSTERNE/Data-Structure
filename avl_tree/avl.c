#include "DS.h"

int max(int a, int b){
        return (a > b) ? a : b;
}

Elm *newNode(int x){
        Elm *node = (Elm *)malloc(sizeof(Elm));
        node->x = x;
        node->height = 1;
        node->len = 1;
        node->L = NULL;
        node->R = NULL;
        return node;
}
int size(Elm *node){
        if(node == NULL){
                return 0;
        }
        else{
                return (size(node->L) + 1 + size(node->R));
        }
}
//This just returns the current height of a node
int height(Elm *node){
        if(node == NULL){
                return 0;
        }
        return node->height;
}
//Calculating the balance factor of a node
int balance(Elm *node){
        if(node == NULL){
                return 0;
        }
        return (height(node->L) - height(node->R));
}
//Right rotate
Elm *right_rotate(Elm *y){
        Elm *x = y->L;
        Elm *T2 = x->R;

        x->R = y;
        y->L = T2;

        y->height = max(height(y->L), height(y->R)) + 1;
        x->height = max(height(x->L), height(x->R)) + 1;

        x->len = size(x);
        y->len = size(y);

        return x;
}
//Left rotate
Elm *left_rotate(Elm *x){
        Elm *y = x->R;
        Elm *T2 = y->L;

        y->L = x;
        x->R = T2;

        x->height = max(height(x->L), height(x->R)) + 1;
        y->height = max(height(y->L), height(y->R)) + 1;

        x->len = size(x);
        y->len = size(y);

        return y;
}

Elm *insert(Elm *node, int x){
        if(node == NULL){
                return newNode(x);
        }
        if(node->x > x){
                node->L = insert(node->L, x);
        }
        else if(node->x < x){
                node->R = insert(node->R, x);
        }
        else{
                return node;
        }
        node->len++;

        node->height = 1 + max(height(node->L), height(node->R));

        int balance_factor = balance(node);

        //Left then Left
        if(balance_factor > 1 && node->L->x > x){
                return right_rotate(node);
        }
        //Left then Right
        if(balance_factor < -1 && node->R->x < x){
                return left_rotate(node);
        }
        //Right then Right
        if(balance_factor > 1 && node->L->x < x){
                node->L = left_rotate(node->L);
                return right_rotate(node);
        }
        //RIght then Left
        if(balance_factor < -1 && node->R->x > x){
                node->R = right_rotate(node->R);
                return left_rotate(node);
        }
        return node;
}

void avl_put(AVL *ptree, int x){
        if(ptree->root == NULL){
                ptree->root = newNode(x);
                return;
        }
        ptree->root = insert(ptree->root, x);
}

Elm *getElm(Elm *node, int x){
        if(node == NULL || node->x == x){
                return node;
        }
        if(node->x < x){
                return getElm(node->R, x);
        }
        else{
                return getElm(node->L, x);
        }
}

Elm *avl_get(const AVL *ptree, int x){
        if(ptree->root == NULL){
                return NULL;
        }
        return getElm(ptree->root, x);
}

Elm *delete(Elm *node, int x){
        if(node == NULL){
                return node;
        }
        if(node->x > x){
                node->L = delete(node->L, x);
        }
        else if(node->x < x){
                node->R = delete(node->R, x);
        }
        else{
                Elm *temp;
                if(node->L == NULL){
                        temp = node->R;
                        return temp;
                }
                else if(node->R == NULL){
                        temp = node->L;
                        return temp;
                }
                temp = node->R;
                while(temp->L != NULL){
                        temp = temp->L;
                }
                node->x = temp->x;

                node->R = delete(node->R, temp->x);
        }
        node->len--;

        if(node == NULL){
                return node;
        }

        node->height = 1 + max(height(node->L), height(node->R));

        int balance_factor = balance(node);

        if(balance_factor > 1 && balance(node->L) >= 0){
                return right_rotate(node);
        }
        if(balance_factor > 1 && balance(node->L) < 0){
                node->L = left_rotate(node->L);
                return right_rotate(node);
        }
        if(balance_factor < -1 && balance(node->R) <= 0){
                return left_rotate(node);
        }
        if(balance_factor < -1 && balance(node->R) < 0){
                node->R = right_rotate(node->R);
                return left_rotate(node);
        }
        return node;
}

void avl_del(AVL *ptree, int x)
{
        ptree->root = delete(ptree->root, x);
}

int min(Elm *node){
        Elm *temp = node;
        while(temp->L != NULL){
                temp = temp->L;
        }
        return temp->x;
}

Elm *deleteMin(Elm *node){
        if(node->L == NULL){
                return node->R;
        }
        node->L = deleteMin(node->L);
        node->len = size(node);
        return node;
}

int avl_delMin(AVL *ptree)
{
        int temp = min(ptree->root);
        ptree->root = deleteMin(ptree->root);
        return temp;
}

void inorder(Elm *p){
        if(p == NULL){
                return;
        }
        inorder(p->L);
        printf("%d %d %d\n", p->x, p->len, p->height);
        inorder(p->R);
}
void avl_inorder(const AVL *ptree)
{
        inorder(ptree->root);
}

int avl_size(const AVL *ptree, int x)
{
        Elm *tree = avl_get(ptree, x);
        if(tree == NULL){
                return -1;
        }
        else{
                return tree->len;
        }
}

int avl_height(const AVL *ptree, int x)
{
        Elm *tree = avl_get(ptree, x);
        if(tree == NULL){
                return -1;
        }
        else{
                return tree->height;
        }
}
