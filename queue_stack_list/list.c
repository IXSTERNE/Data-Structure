#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
{
        p->l_arr[p->l_len] = x;                                                 //Pile on top;
        p->l_len++;       
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{       
        int i, k;
        for(i = p->l_len; i > 0; i--){                                          //Shifting all elements to the right side and replacing the first element with x;
                p->l_arr[i] = p->l_arr[i - 1];
        }
        p->l_len++;
        p->l_arr[0] = x;  
}       

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)                          
{
	int i;                                                                  //Ask if the index is bigger than the array. If yes, pile on top;
        if(pos > p->l_len){
                p->l_arr[p->l_len] = x;
                p->l_len++;
        }
        else {  
        for(i = p->l_len; i > pos; i--){                                        //Simple shift and replace the 1st index with x;
                p->l_arr[i] = p->l_arr[i - 1];
        }
        p->l_len++;
        p->l_arr[pos] = x;   
        }
}


/* p-ийн зааж буй List-н эхлэлээс гаргана.
   List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{                                                                               //Shift the array to left and downsize the array;
        int i;
        for(i = 0; i < p->l_len - 1; i++){
                p->l_arr[i] = p->l_arr[i + 1];
        }
        p->l_len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
        p->l_len--;                                                             //Just downsize the array lol;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
        int i;                                                                  //Find the position and start shifting to left, and downsize the array;
        for(i = pos + 1; i < p->l_len; i++){
                p->l_arr[i - 1] = p->l_arr[i];
        }
        p->l_len--;
          
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void l_print(List *p)
{
        int i;                                                                  
        for (i = 0; i < p->l_len; i++) {
                printf("%d ", p->l_arr[i]);
        }
        printf("\n");
}

/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int l_search(List *p, int x)
{                                                                               //Simple searching algorithm;
	int i, find = -1;
        for(i = 0; i < p->l_len; i++){
                if(p->l_arr[i] == x){
                        find = i;
                        break;
                }
        }
        return find;
}
