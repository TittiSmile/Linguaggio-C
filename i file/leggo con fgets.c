///letto data in un file
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *fp;
    char parola[100];
    char temp[100];
    char *cont;
    char *data;

    fp=fopen("dataa.txt","r");
    if(fp==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    while(1)
    {
        cont=fgets(parola,"100",fp);
        if(cont==NULL)
        {
            break;
        }

        printf("%s",cont);
    }

    fclose(fp);

    return 0;
}
