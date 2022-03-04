#include <stdio.h>
#include<stdlib.h>
#define max 50

int main ()
{
  FILE*fp;
  int a;
  ///bisogna avere un file chiamato file in formato txt(block notest) nella stessa cartella di questo programma
  fp=fopen("prova.txt","r");
  fscanf(fp,"%d",&a);
  fclose(fp);
  printf("il numero letto e': %d",a);
///il programma leggerà il numero contenuto nel file prova.txt

    return 0;
}



