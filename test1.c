#include <stdio.h>
#include <string.h>

int main()
{
   char c[13];
   char cmp[14];
   //scanf("%s", c);
   printf("%s\n", c);
   char e[13] ="PES2UG22CS146";
   for(int i = 10; i <= 12; i++)
   {
        cmp[i] = e[i];
   }
   cmp[13] = '\0';  // Null-terminate the string in cmp array
   printf("cmp\n");
   printf("%s\n", cmp);
   printf("%d",cmp);
   return 0;
}
