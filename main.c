#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
  FILE *pointerOfFile;
  char line[21];
  char *buffer;
  char *pointer;

  buffer = (char *)malloc(1000*sizeof(char));
  memset(buffer, 0, 1000*sizeof(char));
  pointer = buffer;

  pointerOfFile = fopen("test.txt","r");

  if(pointerOfFile != NULL)
  {
    while(!feof(pointerOfFile))
    {
      fgets(line, 21, pointerOfFile);

      if(strcmp(line, "{\n") != 0)
      {
        strcpy(pointer, line);
        pointer += strlen(line);
      }
      else if(strcmp(line, "}\n") != 0)
      {
        strcpy(pointer, line);
        pointer += strlen(line);
      }
    }

    fclose(pointerOfFile);

    pointerOfFile = fopen("test.txt", "w");
    fprintf(pointerOfFile, "%s", buffer);
    fclose(pointerOfFile);
  }

  else
  {
    printf("Could not open the file \n");
  }

  return 0;
  

}