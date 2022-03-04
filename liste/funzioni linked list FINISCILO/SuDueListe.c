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

///TERZO BLOCCO
nodo*AlternaListe(nodo*l1,nodo*l2)
{
    nodo*l3=l1;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
        l2->next=AlternaListe(l1->next,l2->next);
        l3->next=l2;
    }
    return l3;
}

nodo*UnisciListe(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1-> primo < l2->primo)
    {
        l3=l1;
        l3->next=UnisciListe(l1->next,l2);

    }
    else
    {
        l3=l2;
        l3->next=UnisciListe(l1,l2->next);
    }
    return l3;

}

nodo*IntersecaListe(nodo*l1,nodo*l2)
{
    nodo*l3=NULL;
    if(l1)
    {
        l3=IntersecaListe(l1->next,l2);
        if(ricerca(l2,l1->primo))
        {
            l3=intesta(l3,l1->primo);
        }
    }
    return l3;
}

nodo*DifferenzaSimmetricaListe(nodo*l1,nodo*l2,nodo*l3)
{
    if(l1==NULL && l2==NULL)
    {
        return l3;
    }
    else if(l1==NULL)
    {
        l3=incoda(l3,l2->primo);
        return DifferenzaSimmetricaListe(l1,l2->next,l3);
    }
    else if(l2==NULL)
    {
        l3=incoda(l3,l1->primo);
        return DifferenzaSimmetricaListe(l1->next,l2,l3);
    }
    else if(l1->primo < l2->primo)
    {
        l3=incoda(l3,l1->primo);
        return DifferenzaSimmetricaListe(l1->next,l2,l3);
    }
     else if(l1->primo > l2->primo)
    {
        l3=incoda(l3,l2->primo);
        return DifferenzaSimmetricaListe(l1,l2->next,l3);
    }
    return DifferenzaSimmetricaListe(l1->next,l2->next,l3);
}
