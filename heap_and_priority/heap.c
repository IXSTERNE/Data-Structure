#include "DS.h"

static void swim(Heap *p, int);                                         //Static functions are declared here so the order wouldn't
static void sink(Heap *p, int);                                         //matter if the function is called.


int less(const Msg *a, const Msg *b)
{
        if(a->priority > b->priority){                                  //Less the priority, the more important the message is.
                
                return 1;
        }
        else if(a->priority == b->priority){

                if(a->time > b->time){                                  //If both priority are equal, the input time decides which 
                        return 1;                                       //one goes out first.
                }
                else{
                        return 0;
                }
        }
        else{
                return 0;
        }
}

void swap(Msg *a, Msg *b)
{
        Msg temp = *b;
        *b = *a;
        *a = temp;

}


void insert(Heap *p, const Msg x)                                       //Length is saved so insert function can implement swim function.
{
        int temp;
        temp = p->h_len;
        p->h_arr[p->h_len] = x;
        p->h_len++;
        swim(p, temp);
}


static void swim(Heap *p, int k)                                        //The specific number gets checked if it's able to swim up.
{
        while(k >= 0 && less(&p->h_arr[(k - 1) / 2], &p->h_arr[k])){

                swap(&p->h_arr[(k - 1) / 2], &p->h_arr[k]);
                k = (k - 1) / 2;
        }
}


static void sink(Heap *p, int k)                                        //K is (0) in this case.
{                                                                       //The idea is simple, holder and k parameter races like a dual parameter
        while(2 * k + 1 < p->h_len){                                        //array checking procedure.

                int l = 2 * k + 1;

                if(l < p->h_len - 1 && less(&p->h_arr[l], &p->h_arr[l + 1])){
                        l++;
                }
                if(less(&p->h_arr[l], &p->h_arr[k])){
                        break;
                }
                swap(&p->h_arr[l], &p->h_arr[k]);

                k = l; 
        }
}


Msg delMin(Heap *p)                                                     //This function goes with the sink. Swaps the priority number
{                                                                       //with the newly inserted number. So the new number sinks and                                          
        Msg min_holder = p->h_arr[0];                                   //priority gets released.

        swap(&p->h_arr[0], &p->h_arr[p->h_len - 1]);

        p->h_len--;
        sink(p, 0);
        return min_holder;
}

