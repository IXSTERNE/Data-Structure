#include "DS.h"

void s_push(Stack *p, int x){
        Elm *data = malloc(sizeof(Elm));
        data->x = x;
        data->next = p->top;
        p->top = data;
        p->len++;
}

void s_pop(Stack *p){
       Elm *data = p->top;
       p->top = data->next;
       p->len--;
}

void s_print(Stack *p){
      Elm *data = p->top;
      while(data != NULL){
        printf("%d", data->x);
        data = data->next;
      }
}
