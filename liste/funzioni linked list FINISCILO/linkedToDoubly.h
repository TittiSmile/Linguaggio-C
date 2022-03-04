#ifndef LINKEDTODOUBLY_H_INCLUDED
#define LINKEDTODOUBLY_H_INCLUDED
typedef struct LISTA_DOPPIA
{
int primo;
struct LISTA_DOPPIA*prev;
struct LISTA_DOPPIA*next;
}doppia;
///SETTIMO BLOCCO
doppia*nelem2(doppia*tmp2,nodo*p);
doppia*ritdop(nodo*p);
void stampa2(doppia*p2);


#endif // LINKEDTODOUBLY_H_INCLUDED
