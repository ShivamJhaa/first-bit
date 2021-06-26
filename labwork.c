#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *file1;
    char c;

    printf("Content of File1.txt : \n");
    file1=fopen("File1.txt","w");
    while((c=getchar()) != '\n')
    {
        putc(c,file1);
    }
    fclose(file1);
    
    
   if (file1 == NULL)
   {
         puts("Unable to open the files");
         exit(0);
   }

   file1=fopen("File1.txt","r");
   char e;
   while((e=getc(file1)) != EOF)
   printf("%c",e);
   fclose(file1);



}