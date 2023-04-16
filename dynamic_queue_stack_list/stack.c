#include "DS.h"


void s_push(Stack *p, int x)
{     
        Elm *newElm = (Elm *) malloc(sizeof(Elm));
        newElm->x = x;
        newElm->next = p->top;
        p->top = newElm;
        p->len++;   

        /*Top is the current element's next,
        Top points at the new Elm structure,
        */
}


void s_pop(Stack *p)
{
        Elm *popElm = p->top;
        p->top = popElm->next;
        free(p->top);
        p->len--;
}


void s_print(Stack *p)
{
        Elm *print;
        for(print = p->top; print != NULL; print = print->next){
                printf("%d\n", print->x);
        }
}
