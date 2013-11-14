/* fread example: read an entire file
 * http://www.cplusplus.com/reference/cstdio/fread/
 */

#include <stdio.h>
#include <stdlib.h>

int main () {
  FILE * pFile;
  long lSize;
  char * buffer;
  char * temp;
  size_t result;
  int i;

  pFile = fopen ( "myfile.bin" , "a+b" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  /*
  for (i = 0; i < 500; ++i)
  {
        temp = (char *)(malloc(sizeof(char)));

        *temp = 48 + i%10;

        printf("%c", *temp);

        fseek(pFile, 0, SEEK_END);
        fwrite(&temp, sizeof(temp), 1, pFile);
  }
  */

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,sizeof(char),pFile);
  //if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */
  // terminate

  printf("%c\n", *buffer);
//printf("%c\n", *(buffer+1));
  //printf("%c\n", *(buffer+2));

  fclose (pFile);
  free (buffer);
  return 0;
}