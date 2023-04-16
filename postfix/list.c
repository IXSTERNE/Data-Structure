#include "DS.h"


void l_push_back(List *p, Token x){
        TokenElm *list = malloc(sizeof(TokenElm));
        if(list == NULL){
          return;
        }
        list->x = x;
        list->next = NULL;
        if(p->head == NULL && p->tail == NULL){
          p->head = p->tail = list;
        }
        else{
          p->tail->next = list;
          p->tail = list;
        }
        p->len++;
}


void l_push_front(List *p, Token x)
{
        TokenElm *list = malloc(sizeof(TokenElm));
        list->x = x;
        list->next = p->head;
        if(p->head == NULL && p->tail == NULL){
          p->head = p->tail = list;
        }
        else{
          p->head = list;
        }
        p->len++;
}


void l_insert(List *p, Token x, int pos)
{
        if (pos == p->len){
        l_push_back(p , x) ;
        }
        if (pos == 0){
        l_push_front(p, x) ;
        }
        TokenElm *start_head = p->head ;
        TokenElm *list = malloc(sizeof(TokenElm)) ;
        list->x = x;
        int i;
        for(i = 1; i < pos; i++){
        start_head = start_head->next ;
        }
        list->next = start_head->next ;
        start_head->next = list ;
        p->len++; 
}



void l_pop_front(List *p)
{
        TokenElm *list = p->head;
        p->head = p->head->next;
        if(p->head == NULL){
          p->tail = NULL;
        }
        p->len--;
}


void l_pop_back(List *p)
{
        TokenElm *list = p->head ;
        if (p->head->next == NULL){
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
        } 
        else{
          while (list->next != p->tail){
            list = list->next;
            }
            free(p->tail);
            list->next = NULL;
            p->tail = list;
        } 
        p->len--;
}


void l_erase(List *p, int pos)
{
        TokenElm *list = p->head;
        if (pos == 0){

        l_pop_front(p);
        }
        if (pos < p->len && pos > 0){
        int i;
        for(i=1 ;i < pos ;i++){
          if (list->next != NULL){
          list = list->next;
          } 
        }
        list->next = list->next->next;
        p->len--;
        }
}


void l_print(List *p)
{
        TokenElm *list = p->head;
        while(list != NULL){
          if(list->x.flag){
            printf("%d", list->x.val);
          }
          else{
            printf("%c", list->x.op);
          }
          list = list->next;
        }
        printf("\n");
}

