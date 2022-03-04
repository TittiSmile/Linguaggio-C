#ifndef STRUCTSTUDENTE_H_INCLUDED
#define STRUCTSTUDENTE_H_INCLUDED
typedef struct STUDENTE
{
char nome[MAX];
char cognome[MAX];
int matricola;
int esame;
}stud;
///SESTO BLOCCO
stud**leggis(FILE*pf,stud**p);
void stampafile(stud**p,int k,FILE*pf);     ///mi serve solo per verificare che funzioni la funzione lol



#endif // STRUCTSTUDENTE_H_INCLUDED
