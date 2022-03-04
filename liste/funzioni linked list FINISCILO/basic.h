#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED
typedef struct LISTA
{
int primo;
struct LISTA*next;
}nodo;
///PRIMO BLOCCO
nodo*nelem(int a);
nodo*intesta(nodo*p,int a);
nodo*incoda(nodo*p,int a);
nodo*ricerca(nodo*p,int a);
nodo*elimina(nodo*p);
int occorrenza(nodo*p,int a);
nodo*elimina_occorrenza(nodo*p,int a);
void stampa(nodo*p);
nodo*reverse(nodo*p);
int sommaLista(nodo*p);




#endif // BASIC_H_INCLUDED
