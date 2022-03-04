#include <stdio.h>
#include <stdlib.h>
#define max 10
int main ()
{
    FILE*f1;
    FILE*f2;
    FILE*somma;
    int x,y;
    int c1=0,c2=0;

    f1=fopen("n1.txt","r");   ///ovviamente,chiamali come te pare
    if(f1==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    f2=fopen("n2.txt","r");
    if(f2==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    somma=fopen("somma.txt","w");
    if(somma==NULL)
    {
        printf("errore di scrittura file");
        return 1;
    }

    /*while(!EOF)   ATTENZIONE!!!!! non mi va con questo ciclo! lo trovo piuttosto inutile e quindi l'ho tolto
    {
        c1=fscanf(f1,"%d",&x);
        if(c1==EOF)
        {
            break;
        }

        c2=fscanf(f2,"%d",&y);
        if(c2==EOF)
        {
            break;
        }
        fprintf(somma,"la somma e': %d ",x+y);

    }*/

     c1=fscanf(f1,"%d",&x);
     c2=fscanf(f2,"%d",&y);

     fprintf(somma,"il primo numero letto da file e': %d\nil secondo numero letto da file e': %d\n",x,y);
     fprintf(somma,"la somma e': %d ",x+y);
     fprintf(somma,"\nla differenza e': %d ",x-y);


    fclose(f1);
    fclose(f2);
    fclose(somma);

    printf("ho scritto sul file");
    return 0;
}
