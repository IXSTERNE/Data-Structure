#include "DS.h"


void l_push_back(List *p, int x)
{
        Elm *newElm = (Elm *) malloc(sizeof(Elm));
        newElm->x = x;
        newElm->next = NULL;

        if(p->head == NULL && p->tail == NULL){
                p->head = newElm;
                p->tail = newElm;
        }
        else{
                p->tail->next = newElm;
                p->tail = newElm;
        }
        p->len++;
}


void l_push_front(List *p, int x)
{
        Elm *newElm = (Elm *) malloc(sizeof(Elm));
        newElm->x = x;
        newElm->next = p->head;

        if(p->head == NULL && p->tail == NULL){
                p->head = newElm;
                p->tail = newElm;
        }
        else{
                p->head = newElm;
        }
        p->len++;
}

void l_insert(List *p, int x, int pos)
{
        if(pos >= p->len){
                l_push_back(p, x);
                return;
        }
        else if(pos <= 0){
                l_push_front(p, x);
                return;
        }
        else{
                Elm *newElm = (Elm *) malloc(sizeof(Elm));
                newElm->x = x;
                Elm *temp = p->head;

                for(int i = 0; i < pos - 1; i++){
                        temp = temp->next;
                }
                newElm->next = temp->next;
                temp->next = newElm;
                p->len++;
        }
}


void l_pop_front(List *p)
{
        if(p->len == 1){
                free(p->head);
                p->head = NULL;
                p->tail = NULL;
                p->len--;
        }
        else{
                Elm *popElm = p->head;
                p->head = p->head->next;
                free(p->head);
                p->len--;
        }
}


void l_pop_back(List *p)
{
        if(p->len == 1){
                free(p->head);
                p->tail = NULL;
                p->head = NULL;
                p->len--;
        }
        Elm *holder = p->head;
        while(holder->next != p->tail){                     //Closing distance to tail until they cross.
                holder = holder->next;
        }
        free(p->tail);
        p->tail = holder;
        p->tail->next = NULL;
        p->len--;
}


void l_erase(List *p, int pos)
{
        Elm *newElm = p->head;
        if(pos == 0){
                l_pop_front(p);
                return;
        }
        else if(pos == p->len - 1){
                l_pop_back(p);
                return;
        }
        else if(pos > p->len - 1){
             return;
        }
        Elm *holder;
        int i;
        for(holder = p->head, i = 0; i < p->len; i++){
                if(i == pos - 1){
                        Elm *temp = holder->next->next;
                        free(holder->next);
                        holder->next = temp;
                        p->len--;
                        return;
                }
                holder = holder->next;
        }
}


void l_print(List *p)
{
        Elm *print;
        for(print = p->head; print != NULL; print = print->next){
                printf("%d\n", print->x);
        }
}

Elm *l_search(List *p, int x)
{
        Elm *search;
        for(search = p->head; search != NULL; search = search->next){
                if(search->x == x){
                        return search;
                        break;
                }
        }
        return NULL;
}