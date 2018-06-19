#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEBUG 0
#define MAX 512

char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    code = malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;
    }

    //terminate with the null character
    code[n] = '\0';        

    return code;
}

void strclean (char* src) {
    // Run two pointers in parallel.

    char *dst = src;

    // Process every source character.

    while (*src) {
        // Only copy (and update destination pointer) if suitable.
        // Update source pointer always.

        if (isalpha(*src)) *dst++ = *src;
        src++;
    }

    // Finalise destination string.

    *dst = '\0';
}


int main(int argc, char **argv) {

  int i = 0;
  char key[MAX];
  char pt[MAX];

  
  if(argc != 3)
  {
    printf("Please insert the correct parameters");
    return 1;

    // makes sure only three total words are taken from command line
  }

  for(i;i<1;i++){
    if(argc=0){
      argc++;
    }
    // skips C from recording the first argument as a string because that's extra work

    if(argc=1){
      strcpy(key, argv[argc]);
//      printf("%s\n", key);

    }
    // makes working string from command line argument
    
    if(argc=2){
      strcpy(pt, argv[argc]);
//      printf("%s\n", pt);
    }
    // working string from second command line argument
  }

// File I/O

char *rawkey = readFile(key);
char *rawpt = readFile(pt);




// Clean inputs

char *cleankey;
char *cleanpt;


strclean(rawkey);
strclean(rawpt);

for(int i = 0; rawkey[i]; i++){
  rawkey[i] = tolower(rawkey[i]);
}

for(int i = 0; rawpt[i]; i++){
  rawpt[i] = tolower(rawpt[i]);
}

printf("\n\nVigenere key:\n\n%s\n\n", rawkey);
printf("Plaintext:\n\n%s\n\n", rawpt);

return 0;
}