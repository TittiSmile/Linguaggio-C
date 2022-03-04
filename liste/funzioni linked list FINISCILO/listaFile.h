#ifndef LISTAFILE_H_INCLUDED
#define LISTAFILE_H_INCLUDED
///NONO BLOCCO
nodo*leggiFile(FILE*pf);
nodo*scriviFile(FILE*pf,int dim);
nodo*modificaFile(nodo*p,FILE*pf);
int LunghezzaFile(FILE*pf);
#endif // LISTAFILE_H_INCLUDED
