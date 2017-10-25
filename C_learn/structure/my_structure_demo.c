#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Cars
{
   char name[10];
   int weight[10];
   int id[10];
   char *p;
};

/*函数声明*/
void listCars();
int main( )
{
   struct Cars car = {"奔驰",700,1};;
   /*初始化car*/
   //car.name="奔驰";
   //car.weight=700;
   //car.id=1;
   /*为指针区域赋值*/
   char *c = (char*)malloc(10*sizeof(char));
   strcpy(c,"hello");
   car.p = c;

   printf("输出car\n");
   printf("car.name: %s\n",car.name);
   printf("car.p: %s\n",car.p);

   return 0;
}
