#include <time.h>
#include <limits.h>
#define MAX 20
#include "basic.h"
#include "SuDueListe.h"
#include "listaSuK.h"
#include "ordinamento.h"
#include "other.h"
#include "structStudente.h"
#include "linkedToDoubly.h"


///QUARTO BLOCCO
nodo*EliminaMaggioriK(nodo*p,int k)
{
    nodo*tmp=p;
    if(p!=NULL)
    {
        if(p->primo > k)
        {
            p=EliminaMaggioriK(p->next,k);
            free(tmp);
        }
        else
        {
            p->next=EliminaMaggioriK(p->next,k);
        }
    }
    return p;

    /*nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    p->next=EliminaMaggioriK(p->next,k);    ///scorro p->next perchè devo modificare la lista di partenza
    if(p->primo>k)
    {
       tmp=p;
       p=p->next;
       free(tmp);
    }
    return p;*/
}

nodo*ListaConK(nodo*p,int k) ///toglie tutti i numeri diversi da k e li mette in un'altra lista
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=ListaConK(p->next,k); ///metto tmp=... perchè mi servirà  una lista nuova!
    if(p->primo==k)
    {
        tmp=incoda(tmp,p->primo);
    }
    return tmp;
}
