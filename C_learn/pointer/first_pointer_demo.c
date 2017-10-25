#include <stdio.h>

int main( )
{
   int var = 20;
   int *ip;

   ip = &var;

   printf("var的address: %p\n",&var);
   printf("ip的值: %p\n",ip);
   printf("*ip的值: %d\n",*ip);

   return 0;
}
