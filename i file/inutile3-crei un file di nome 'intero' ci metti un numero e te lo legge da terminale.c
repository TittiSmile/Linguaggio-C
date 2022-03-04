#include<stdlib.h>
#include<stdio.h>

int main() {
  FILE *fd;
  int x;


		/* apre il file, legge il numero, chiude */

  fd=fopen("intero.txt", "r");

  fscanf(fd, "%d", &x);

  fclose(fd);


		/* stampa il numero */

  printf("Il numero letto da file e' %d\n", x);

  return 0;
}
