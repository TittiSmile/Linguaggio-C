#include <stdio.h>

int main()
{
    
    int i =0;
    int dim = 0;
    int elemento;
    printf("quanto vuoi grande l'array? ");
    scanf("%d",&dim);
    int a[dim];
    for(i=0;i<dim;i++){
        printf("inserisci elemento: ");
        scanf("%d",&a[i]);
        
    }
    
     for(i=0;i<dim;i++){
        printf("array: %d ",a[i]);
    }

    return 0;
}
