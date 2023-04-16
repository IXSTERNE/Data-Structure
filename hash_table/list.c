#include "DS.h"


void l_push_back(List *p, Student x)
{
        Elm *newElm = malloc(sizeof(Elm));
        newElm->x = x;
        newElm->next = NULL;

        if(p->head == NULL && p->tail == NULL){
            p->head = p->tail = newElm;
        }
        else{
            p->tail->next = newElm;
            p->tail = newElm;
        }
        p->len++;
}


void l_push_front(List *p, Student x)
{
        Elm *newElm = malloc(sizeof(struct Elm));
        newElm->x = x;
        newElm->next = p->head;

        if(p->head == NULL && p->tail == NULL){
            p->head = p->tail = newElm;
        }
        else{
            p->head = newElm;
        }
        p->len++;
}

void l_insert(List *p, Student x, int pos)
{
        if(pos == p->len){
            l_push_back(p, x);
            return;
        }
        if(pos == 0){
            l_push_front(p, x);
            return;
        }
        Elm *temp = p->head;
        Elm *newElm = (Elm *)malloc(sizeof(Elm));
        newElm->x = x;

        int i;
        for(i = 1; i < pos; i++){
            temp = temp->next;
        }
        newElm->next = temp->next;
        temp->next = newElm;
        p->len++;
}



void l_pop_front(List *p)
{
        Elm *popElm = p->head;
        p->head = p->head->next;
        if(p->head == NULL){
            p->tail = NULL;
        }
        p->len--;
}


void l_pop_back(List *p)
{
        Elm *holder = p->head;
        if(p->head->next == NULL){
                p->head = NULL;
                p->tail = NULL;
        }
        else{
                while(holder->next != p->tail){
                        holder = holder->next;
                }
                holder->next = NULL;
                p->tail = holder;
            }
        p->len--;
}


void l_erase(List *p, int pos)
{
        Elm *eraseElm = p->head;

        if(pos == 0){
            l_pop_front(p);
        }
        if(pos < p->len && pos > 0){
            int i;
            for(i = 1; i < pos; i++){
                if(eraseElm->next != NULL){
                    eraseElm = eraseElm->next;
                }
            }
            eraseElm->next = eraseElm->next->next;
            p->len--;
        }
}


void l_print(List *p)
{
        Elm *print = p->head;
        while(print != NULL){
            printf("%d\n", print->x);
            print = print->next;
        }
}


Elm *l_search(List *p, const char id[])
{
        Elm *search = p->head;
        while(search != NULL){
            if(strcmp(search->x.id, id) == 0){
                return search;
            }
            search = search->next;
        }
        return NULL;
}
