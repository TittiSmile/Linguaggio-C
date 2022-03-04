#include <stdio.h>/// questo programma è in C ma vale anche per C++. le funzioni non cambiano
#include <stdlib.h>
typedef struct LISTA
{
    int primo;
    struct LISTA *next;
}nodo;
///di seguito,farò il prototipo delle funzioni. in questo programma non c'è un main poichè non è altro che una raccolta di
/// funzioni utili da utilizzare con le struct o in altre tipologie

nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p,int a);
int occorrenze(nodo*p,int a);
nodo*elocc(nodo*p,int a);   ///elimina le occorrenze di un numero
int somma(nodo*p); /// somma tutti gli elementi della LISTA
nodo*rewerse (nodo*p);
void stampa(nodo*p);
///funzioni con operazioni su due liste
nodo*alterna(nodo*l1,nodo*l2);
nodo*unisci(nodo*l1,nodo*l2);
nodo*interseca(nodo*l1,nodo*l2);
///funzioni con un numero k
nodo*elk(nodo*p,int k);// elimina tutti i numeri maggiori di k
nodo*mk(nodo*p,int k); //i numeri maggiori di k vanno dopo i numeri minori di k. se k=4 1 6 4 8 2 la lista sarà: 1 2 4 6 8. non sempre i numeri sono i ordine
nodo*diversik(nodo*p,int k); // i numeri diversi da k andranno in un'altra lista
///funzioni di ordinamento
nodo*incoda2(nodo*p,nodo*tmp); //serve quando non abbiamo la funzione 'nelem' e abbiamo bisogno della creazione di due elemtni struct
nodo*inordine(nodo*p,int a);//invece di inserire gli elementi in testa/in coda, te li fa inserire in ordine (dal più piccolo al più grande)
nodo*crescente(nodo*p); // a seconda delle necessità,può essere anche decrescente
nodo*ordina(nodo*p,nodo*tmp);//serve per la funzione crescente. ti ordina i numeri in maniera crescente
///varie funzioni
void dealloca(nodo*p);// serve a deallocare memoria,NON ad eliminare un'intera lista
nodo*eliminadoppi(nodo*p); //elimina tutti i numeri(in questo caso) che sono presenti più volte nella lista
int palindromo(int a[],int n); //questa è una vedifica per un ARRAY non per una lista!!
nodo*leggi(FILE *input);//legge i file



int main()
{
    ///SARA' VUOTO!!!!!

    nodo*l1=NULL;
    nodo*l2=NULL;
    nodo*l3=NULL;
    int i=0,k,dim,n,a,dom,m,cas,dupl;

    FILE*pf=NULL;

//    doppia*l4=NULL;

                                                           ///***PRIMO BLOCCO***
    printf("quanto vuoi grande la tua lista? ");
    scanf("%d",&dim);
    for(i=0;i<dim;i++)
    {
        printf("inserisci %d elemento lista 1:   ",i+1);
        scanf("%d",&n);
        l1=inordine(l1,n);
    }
    printf("stampo la lista:");
    stampa(l1);

    return 0;
}


nodo*nelem(int a)
{
    nodo*q=(nodo*)malloc(sizeof(nodo));// è equivalente a:  struct LISTA *q=(struct LISTA*)malloc(sizeof(struct LISTA*))
    ///in C++ NON si usa malloc ma:  nodo*q=new nodo;  o anche: struct LISTA *q=new struct LISTA;
    q->primo=a;
    q->next=NULL;
    return q;
}

nodo*intesta(nodo*p,int a)
{
    nodo*q=nelem(a);
    q->next=p;
    return q;
}


nodo*incoda(nodo*p,int a)
{///versione RICORSIVA
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

nodo*ricerca(nodo*p,int a)
{
    nodo*trovato=NULL;
    for(;p!=NULL && trovato==NULL;p=p->next)
    {
        if(p->primo==a)
        {
            trovato=p;
        }
    }
    return p;
}

nodo*elimina(nodo*p,int a)
{
     nodo*tmp;
     for(;p!=NULL;p=tmp)
     {
         tmp=p->next;
         p->next=NULL;
         free(p);  ///in C++ si usa:  delete p;

     }
     return p;
}

int occorrenze(nodo*p,int a)
{
    int flag=0;
    if(p!=NULL)
    {
        if(p->primo==a)
        {
            flag=1+occorrenze(p->next,a);
        }
        else
        {
            flag=occorrenze(p->next,a);
        }
    }
    return flag;
}

nodo*elocc(nodo*p,int a)
{
   nodo*tmp=p;
   if(p!=NULL)
   {
       if(p->primo==a)
       {
           p=elocc(p->next,a);
           free(tmp);
       }
       else
       {
           p->next=elocc(p->next,a);
       }
   }
   return p;
}

int somma(nodo*p)
{
  int sum=0;
  if(p==NULL)
  {
      return 0;
  }
  else
  {
      sum=somma(p->next);
      sum=sum+(p->primo);   ///si può fare anche sum+=p->primo
      return sum;
  }
}

nodo*rewerse (nodo*p)
{
    if(p==NULL)
    {
        return 0;
    }
    rewerse(p->next);
    printf("\n\n %d",p->primo);
    /*
    in C++:
    if(p==NULL)
        return 0;
    rewerse(p->next)
    cout<<"Lista: \n "<<p->primo<< endl;
    */
}

void stampa(nodo*p)
{
    while(p!=NULL)
    {
        printf("\n\n %d",p->primo);
        p=p->next;
    }

    /// in C++:
    /*
    while(p!=NULL)
        cout<<"Lista:\n"<<p->primo<<endl;
        p=p->next;
    */
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


nodo*alterna(nodo*l1,nodo*l2)
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
     l2->next=alterna(l1->next,l2->next);
     l3->next=l2;
 }
  return l3;
}

nodo*unisci(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else if(l1->primo < l2->primo)
    {
        l3=l1;
        l3->next=unisci(l1->next,l2);
    }
    else
    {
        l3=l1;
        l3->next=unisci(l1,l2->next);
    }
    return l3;
}


nodo*interseca(nodo*l1,nodo*l2)
{
    nodo*l3;
    if(l1)
    {
        l3=interseca(l1->next,l2);
        if(ricerca(l2,l1->primo))  //per 'ricerca' vedi più sopra
        {
            l3=intesta(l3,l1->primo); //per 'intesta' vedi più sopra
        }
    }
    return l3;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

nodo*elk(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    else
    {
         p=elk(p->next,k);
         if(p->primo>k)
         {
             tmp=p;
             p=p->next;
             free(tmp); //in C++:  delete tmp;
         }
    }
    return p;
    ///altro modo per scrivere la funzione!!
    /*
    nodo*tmp=p;
    if(p!=NULL)
    {
       if(p->primo >k
       {
         p=elk(p->next,k);
       }
       else
       {
         p->next=elk(p->next,k);
       }
    }
    return p;
    */
}

nodo*mk(nodo*p,int k)
{
   nodo*tmp;
   if(p==NULL || p->next==NULL)
   {
       return p;
   }
   tmp=mk(p->next,k);
   if(p->primo >k)
   {
       p->next=tmp;
       return p;
   }
   else
   {
       tmp=incoda2(tmp,p);//vedi più giù
       return tmp;
   }
}

nodo*diversik(nodo*p,int k)
{
    nodo*tmp;
    if(p==NULL)
    {
        return p;
    }
    tmp=diversik(p->next,k);
    if(p->primo !=k)
    {
        tmp=intesta(tmp,p->primo);
        return tmp;
    }
}



nodo*incoda2(nodo*p,nodo*tmp)
{
  if(p!=NULL)
  {
      tmp->next=p;
      return tmp;
  }
  else
  {
      p->next=incoda2(p->next,tmp);
      return p;
  }
}

nodo*inordine(nodo*p,int a)    ///inserisci direttamente in ordine
{
  /*if(p==NULL || p->primo>a)
  {
      nodo*tmp=(nodo*)malloc(sizeof(nodo));
      tmp=nelem(a);
      tmp->next=p;
      p=tmp;
  }
  else
  {
      p->next=inordine(p->next,a);
  }
  return p;*/
   nodo*tmp=(struct LISTA*)malloc(sizeof(struct LISTA));
    if(p==NULL || p->primo > a)
    {
        tmp=nelem(a);
        tmp->next=p;
        p=tmp;
    }
    else
    {
        p->next=inordine(p->next,a);
    }
    return p;

}

nodo*crescente(nodo*p)
{
    nodo*tmp;
    nodo*nlista=NULL;
   while(p!=NULL)
   {
       tmp=p;
       p=p->next;
       nlista=ordina(nlista,tmp);
   }
   return nlista;
}

nodo*ordina(nodo*p,nodo*tmp)
{
    if(p==NULL || p->primo > tmp->primo) //metto > perchè ci riferiamo alla funzione che vuole numeri in ordine CRESCENTE
    {
       tmp->next=p;
       p=tmp;
    }
    else
    {
        p->next=ordina(p->next,tmp);
    }
    return p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////



void dealloca(nodo*p)
{
    if(p!=NULL)
    {
        dealloca(p->next);
        p->next=NULL;
        free(p);
    }
}

nodo*eliminadoppi(nodo*p)
{
    nodo*p1=p;
    nodo*p2=p;
    if(p==NULL)
    {
        return p;
    }
    p->next=eliminadoppi(p->next);
    while(p1!= NULL && p1->next!=NULL)
    {
        p1=p1->next;
        if(p->primo == p1->primo)
        {
            p2=p->next;
            free(p);
        }
    }
    return p2;
}

int palindromo(int a[],int n)
{
      if(n==0 || n==1)
      {
          return 1;
      }
      else if(a[0]!=a[1-n])
      {
          return 0;
      }
      else
      {
          return palindromo(&a[1],n-2);
      }
}

///serve struct studente
nodo*leggi(FILE *input)
{
    nodo*p=NULL;
    nodo*tmp;
    while(feof(input))
    {
      tmp=(nodo*)malloc(sizeof(nodo*));
     //  fscanf(input,"%s %d",tmp->nome, &tmp->primo);
       p=incoda2(p,tmp);
    }
    return p;
}



