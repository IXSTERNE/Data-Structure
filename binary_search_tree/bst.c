#include "DS.h"
/*Idk what's not working man, ah please help*/


void *insert(Elm *p, int x)
{
       if(p->x < x){


               p->len++;
               /* If we're comparing numbers it's adding length on the main number.
               Since adding numbers is definite when comparing.
               Also to note: It's comparing with a certain number only once so,
               a number can't get +2 height or length at a time. */


               if(p->R == NULL){
                       Elm *newRight = (Elm *)malloc(sizeof(Elm));
                       newRight->x = x;
                       newRight->height = 1;
                       newRight->len = 1;
                       newRight->L = NULL;
                       newRight->R = NULL;
                       p->R = newRight;
               }
               else{ 
                       insert(p->R, x);
               }       
       }
       else{  
               p->len++;


               if(p->L == NULL){
                       Elm *newLeft = (Elm *)malloc(sizeof(Elm));
                       newLeft->x = x;
                       newLeft->height = 1;
                       newLeft->len = 1;
                       newLeft->L = NULL;
                       newLeft->R = NULL;
                       p->L = newLeft;
               }
               else{  
                       insert(p->L, x);
               }
       }
      
       /*Deciding if it should add height or not*/


       int left_height_count = p->L == NULL ? 1 : p->L->height + 1;
       int right_height_count = p->R == NULL ? 1 : p->R->height + 1;
       p->height = left_height_count > right_height_count ? left_height_count : right_height_count;
}





void bs_put(BST *ptree, int x)
{ 
       if(ptree->root == NULL){
               Elm *newRoot = (Elm *)malloc(sizeof(Elm));
               newRoot->x = x;
               newRoot->height = 1;
               newRoot->len = 1;
               newRoot->L = NULL;
               newRoot->R = NULL;
               ptree->root = newRoot;
               return;
       }
       insert(ptree->root, x);
}


Elm *bs_get_elm(Elm *p, int x)
{
       if(p == NULL|| x == p->x){
               return p;
       }
       if(x > p->x){
               bs_get_elm(p->R, x);
       }
       else{
               bs_get_elm(p->L, x);
       }
}


Elm *bs_get(const BST *ptree, int x)
{
       bs_get_elm(ptree->root, x);
}




Elm *delete(Elm *p, int x)
{
       Elm *holder;


       if(p == NULL){
               return p;
       }
       if(p->x > x){
               p->L = delete(p->L, x);
       }
       else if(p->x < x){
               p->R = delete(p->R, x);
       }
       else{
               if(p->L == NULL){
                       holder = p->R;
                       return holder;
               }
               else if(p->R == NULL){
                       holder = p->L;
                       return holder;
               }
               holder = p->R;
               while(holder->L != NULL){
                       holder = holder->L;
               }
               p->x = holder->x;
               p->R = delete(p->R, p->x);
       }


       int left_height_count = p->L == NULL ? 1 : p->L->height + 1;
       int right_height_count = p->R == NULL ? 1 : p->R->height + 1;
       p->height = left_height_count > right_height_count ? left_height_count : right_height_count;
       p->len--;
       return p;
}


void bs_del(BST *ptree, int x)
{
       ptree->root = delete(ptree->root, x);
}


int findMin(Elm *p)
{      
       Elm *temp = p;
       while(temp->L != NULL){
               temp = temp->L;
       }
       return temp->x;
}


Elm *del_min_elm(Elm *p)
{
       if(p->L == NULL){
               return p->R;
       }
       p->L = del_min_elm(p->L);
       p->len--;
       return p;
}



int bs_delMin(BST *ptree)
{
       int temp;
       temp = findMin(ptree->root);
       ptree->root = del_min_elm(ptree->root);
       return temp;
}


void bs_inorder_print(Elm *p)
{
       if(p == NULL){
               return;
       }
       bs_inorder_print(p->L);
       printf("%d, %d, %d\n", p->x, p->len, p->height);
       bs_inorder_print(p->R);
}


void bs_inorder(const BST *ptree)
{
       bs_inorder_print(ptree->root);
}




int get_rank(Elm *p, int x)
{
       if(p == NULL){
               return 0;
       }
       if(p->x > x){
               return get_rank(p->L, x);
       }


       int temp = p->L == NULL ? 1 : p->len + 1;
       return temp + get_rank(p->R, x);
}


int bs_rank(const BST *ptree, int x)
{
       if(ptree->root != NULL){
               return get_rank(ptree->root, x);
       }
}




int bs_size(const BST *ptree, int x)
{
       Elm *p = bs_get(ptree, x);
       return p == NULL ? -1 : p->len;
}

Elm *bs_get_floor(Elm *p, int x){
       if(p == NULL){
               return NULL;
       }
       if(p->x > x){
               return bs_get_floor(p->L, x);
       }
       else if(p->x == x){
               return p;
       }
       else{
               Elm *temp = bs_get_floor(p->R, x);
               if(temp == NULL){
                       return p;
               }
               else{
                       return temp;
               }
       }
}

Elm *bs_floor(const BST *ptree, int x)
{
       if(ptree->root == NULL){
               return NULL;
       }     
       else{
               return bs_get_floor(ptree->root, x);
       }
}
Elm *ceiling(Elm *p, int x){


       if(p == NULL){
               return NULL;
       }
       if(p->x < x){
               return ceiling(p->R, x);
       }
       else if(p->x == x){
               return p;
       }
       else{
               Elm *temp = ceiling(p->L, x);
               if(temp == NULL){
                       return p;
               }
               else{
                       return temp;
               }
       }
}


Elm *bs_ceiling(const BST *ptree, int x)
{
       if(ptree->root == NULL){
               return NULL;
       }
       else{
               return ceiling(ptree->root, x);
       }
}




int bs_height(const BST *ptree, int x)
{
       Elm *p = bs_get(ptree, x);
       return p == NULL ? -1 : p->height;
}

