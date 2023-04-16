#include "DS.h"
// I just wanna let people know that I worked on this assignment for 3 days and things didn't seem
// to work out and today I finally figured out what was screwing me up. Can you imagine that a single space line
// ruined my whole sleep schedule and my self confidence?
// ("%d\n") and ("%d \n") are apparently different. ffs;


/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{       
        p->tree.a[p->tree.len] = x;
        p->tree.len++;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{                                                                                       //test comment;
        int left_child_idx, found = -1;

        left_child_idx = (2 * idx + 1);                                                 //Left child = 2n + 1
        if(left_child_idx < p->tree.len){
        found = left_child_idx;
        }
        return found;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
        int right_child_idx, found = -1;

        right_child_idx = (2 * idx + 2);                                                //Right child = 2n + 2
        if(right_child_idx < p->tree.len){
        found = right_child_idx;
        }
        return found;
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
        int i, found = -1;

        for(i = 0; i < p->tree.len; i++){
                if(x == p->tree.a[i]){
                found = i;
                break;                                                                  //Funny that you see that there's a break because it's supposed 
                }
        }                                                                               //to return the 1st matching number and that's it lol;
        return found;                                                                   //Wastaed some quality time here;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
        if(idx > 0){
                printf("%d\n", p->tree.a[(idx - 1 )/ 2]); 
                cb_ancestors(p, (idx - 1) / 2);
        }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{       
      int i, value = p->tree.len, increment = 0;                                      //Basic recursion n/2 and counts it;

        for(i = 0; value > 0; i++){
        value = value / 2;
        increment++;
        }
        return increment;  
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{       
        if (idx == p->cb_len - 1 && idx % 2 == 1){
                return -1;
        }
        else{
                if(idx < p->tree.len && idx > 0){
                        if (idx % 2 == 1){
                                return idx + 1;
                        }
                        else{
                                return idx - 1;
                        }
                }
                else{
                        return -1;
                }
        }
}
/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
        if(idx < p->tree.len){
                printf("%d\n", p->tree.a[idx]);
                cb_preorder(p, 2 * idx + 1);
                cb_preorder(p, 2 * idx + 2);
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
        if(idx < p->tree.len){
                cb_inorder(p, 2 * idx + 1);
                printf("%d\n", p->tree.a[idx]);
                cb_inorder(p, 2 * idx + 2);
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
        if(idx < p->tree.len){
                cb_postorder(p, 2 * idx + 1);
                cb_postorder(p, 2 * idx + 2);
                printf("%d\n", p->tree.a[idx]);
        }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
        if(idx < p->tree.len){
                if(2 * idx + 1 >= p->tree.len){
                        printf("%d\n", p->tree.a[idx]);
                }
                cb_leaves(p, 2 * idx + 1);
                cb_leaves(p, 2 * idx + 2);
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
        if(idx < p->tree.len){
                
                cb_preorder(p, 2 * idx + 1);
                cb_preorder(p, 2 * idx + 2);
        }
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
        return p->tree.len;	
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
        int i = cb_search(p, x), count = 0;

        if(cb_search(p, x) == - 1){
                return -1;
        }
        else{
                while(i > 0){
                        i = (i - 1) / 2;
                        count++;
                }
                return count;
        }
}




