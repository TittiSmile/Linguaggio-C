#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE*fp;
    char parola[100];
    char temp[100];
    char *data;
    char *cont;

    fp=fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("erroe di apertura");
        return 1;
    }



    fclose(fp);




    return 0;
}
