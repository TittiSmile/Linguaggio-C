#include <stdio.h>
int main ()
{
    int a=3;
    char b[5]={'c','a','c','c','a'};
    FILE *fp;
    fp=fopen("provaa.txt","w"); ///mi crea un file .txt se il file esiste già,sovrascrive tutto ciò che è scritto.
    ///se esiste e vuoi aggiungere qualcosa,invece di 'w' puoi mettere 'a'
    if(fp==NULL)
    {
        printf("errore di apertura");
    }

    fprintf(fp,"\n\n%d\n\n%s",a,b);

    fclose(fp);



}
