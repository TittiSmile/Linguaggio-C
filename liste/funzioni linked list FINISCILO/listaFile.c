#include <stdio.h>
#include <stdlib.h>
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

///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p)
{
    int i=0;
    int dim=0;
    pf=fopen("qw.txt","r");
    if(pf)                       ///ho scritto così per evitare di farlo nel MAIN
    {
      fscanf(pf," %d ",&dim);
        for(i=0;i<dim;i++)
        {
        p[i]=(stud*)malloc(sizeof(stud));
        fscanf(pf,"%s %s %d %d ",p[i]->cognome,p[i]->nome,&p[i]->matricola,&p[i]->esame);
        }
    }
    else
    {
        printf("errore");
    }
    fclose(pf);

    return p;
}

void stampafile(stud**p,int k,FILE*pf)
{
    int i=0;
    int dim=0;
    pf=fopen("qw.txt","r");
    if(pf)
    {
        fscanf(pf," %d ",&dim);
        for(i=0;i<dim;i++)
        {
            if(p[i]->esame>k)
            {
                printf("%s %d",p[i]->cognome,p[i]->matricola);
            }
        }
    }
    else
    {
        printf("errore");
    }

    fclose(pf);

}

