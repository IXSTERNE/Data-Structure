#include "DS.h"



void ht_insert(HashTable *p_hash, const Student x)
{
        int h = ht_hash(x.id);
        Elm *p_elm = l_search(&p_hash->h[h], x.id);
        if (p_elm == NULL)
                l_push_back(&p_hash->h[h], x);
}



int ht_hash(const char s[])
{
        unsigned long int a = 0;
        unsigned int i = 0;
        while(s[i] != '\0'){
                a = a * 31 + s[i];
                i++;
        }
        return (a) % HASH_TABLE_SIZE;
}


void ht_init(HashTable *p_hash)
{
        int i;
        p_hash->h = (List *) malloc(sizeof(List) * HASH_TABLE_SIZE);
        for (i = 0; i < HASH_TABLE_SIZE; i++)
                p_hash->h[i].head = p_hash->h[i].tail = NULL;
}


Student *ht_search(HashTable *p_hash, const char id[])
{
       Elm *search = p_hash->h[ht_hash(id)].head;

       while(search != NULL){
                if(strcmp(search->x.id, id) == 0){
                        return &search->x;
                }
                search = search->next;
       }
       return NULL;
}


void ht_update(HashTable *p_hash, const Student x)
{
        if(ht_search(p_hash, x.id) == NULL){
                ht_insert(p_hash, x);
        }
        else{
                Student *update = ht_search(p_hash, x.id);
                *update = x;
        }
}


void ht_del(HashTable *p_hash, const char id[])
{
        Elm *delete = p_hash->h[ht_hash(id)].head;
        while(delete != NULL){
                if(strcmp(delete->x.id, id) == 0){

                        *delete->x.id = '\0';
                        *delete->x.ovog = '\0';
                        *delete->x.ner = '\0';
                }
                delete = delete->next;
        }
}    


void ht_release(HashTable *p_hash)
{
        int i;
        for (i = 0; i < HASH_TABLE_SIZE; i++) {
                while (p_hash->h[i].head != NULL)
                        l_pop_front(&p_hash->h[i]);
        }
        free(p_hash->h);
}


void student_print(FILE *fout, const Student *p)
{
        if (p == NULL)
                fprintf(fout, "xooson\n");
        else
                fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}
