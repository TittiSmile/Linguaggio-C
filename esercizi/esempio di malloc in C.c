#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   //questa libreria è facoltativa!! serve solo per verificare che l'array non sia NULL


int main ()
{
    int *array;
    int n,i=0;
    printf ("Inserisci la grandezza dell'array ");
    scanf("%d",&n);
    array=(int*)malloc(n*sizeof (int));
    assert (array!=NULL);
    for (i=0;i<n;i++)
    {
        printf("inserisci l'elemento ");
        scanf ("%d",&array[i]);
    }
    
    printf("\nElementi acquisiti\n\n");
    printf("Elemento\t indirizzo\t valore\n\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t\t %d\t\t %d\t\t\n",i,&array[i],array[i]);
    }
    
    free(array);   // libera memoria dopo aver utilizzato array. questo passaggio è necessario al termine di ogni allocazione dinamica 
                   //si può anche usare la dicitura void free(void*array);
       
    
    return 0;
}

