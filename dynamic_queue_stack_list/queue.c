#include "DS.h"


void q_push(Queue *p, int x)
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
        /* Queue next stores the address of it's next element */
}


void q_pop(Queue *p)
{
        Elm *popElm = p->head;
        p->head = p->head->next;
        if(p->head == NULL){
                p->tail = NULL;
        }
        p->len--;
        
        /* This one is quite problematic */
}


void q_print(Queue *p)
{
        Elm *print;
        for(print = p->head; print != NULL; print = print->next){
                printf("%d\n", print->x);
        }
}
