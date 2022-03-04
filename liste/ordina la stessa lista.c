#include <stdio.h>
#include <malloc.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;

nodo*nelem(int a);
nodo*incoda(nodo*p,int a);
nodo*ordina(nodo*p);///SERVE AD ORDINARE LA LISTA SENZA RITORNARNE UNA NUOVA
void stampa(nodo*p);

int main ()
{
    nodo*l1=NULL;
    nodo*l2=NULL;
    int a;

    l1=incoda(l1,3);l1=incoda(l1,5);l1=incoda(l1,4);l1=incoda(l1,2);
    stampa(l1);
    printf("\n\n");
    l1=ordina(l1);
    stampa(l1);




    return 0;
}

nodo*nelem(int a)
{
  nodo*q=(struct LISTA*)malloc(sizeof(struct LISTA));
  q->primo=a;
  q->next=NULL;
  return q;
}

nodo*incoda(nodo*p,int a)
{
    if(p==NULL)
    {
        p=nelem(a);
    }
    else
    {
        p->next=incoda(p->next,a);
    }
    return p;
}

nodo*ordina(nodo*p)
{
    int cont,flag;
    nodo*cur;
    nodo*tmp;
    if (p!=NULL && p->next!=NULL)
    {
		while(cont!=0)
		{
		    cur = p;
			cont = 0;
			while (cur->next!=NULL)
			{
				tmp = cur;
				cur = cur->next;
				if ((tmp->primo) > (cur->primo))
				{
                    flag = tmp->primo;
					tmp->primo = cur->primo;
					cur->primo= flag;
					cont = 1;
				}
			}
		}
	}

	return p;
}


void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n%d\n",p->primo);
        p=p->next;
    }
}


