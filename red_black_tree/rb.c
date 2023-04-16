#include "DS.h"


int less(const Student *a, const Student *b)
{
	
}

void rb_put(RBT *ptree, const Student *px)
{
        
}


Elm *rb_get(const RBT *ptree, const char id[])
{
        
}


void rb_del(RBT *ptree, const char id[])
{

}

void print(Elm *p)
{
	if (p)
		printf("%s %s %d %.1f\n", p->x.name, p->x.id, p->x.age, p->x.gpa);
	else
		printf("None\n");
}
