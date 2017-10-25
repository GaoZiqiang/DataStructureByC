/*
==========================================================================================
                    串的基本操作
            By~fanxingzju       2014.04.23
1.StrAssign(&T, chars)
初始条件：chars是字符串常量
操作结果：生成一个其值等于chars的串T
2.StrCopy(&T, S)
初始条件：串S存在
操作结果：由串S复制的串T
3.StrEmpty(S)
初始条件：串S存在
操作结果：若S为空串，则返回true，否则返回false
4.StrCompare(S, T)
初始条件：串S和T存在
操作结果：若S > T，则返回值 > 0；若S = T，则返回值 = 0；若S < T，则返回值 < 0
5.StrLength(S)
初始条件：串S存在
操作结果：返回S的元素个数，称为串的长度
6.ClearString(&S)
初始条件：串S存在
操作结果：将S清为空串
7.Concat(&T, S1, S2)
初始条件：串S1和S2存在
操作结果：用T返回由S1和S2联接而成的新串
8.SubString(&Sub, S, pos, len)
初始条件：串S存在，1≦pos≦Strlength(S)且0≦len≦Strlength(S)-pos+1
操作结果：用Sub返回串S的第pos个字符起长度为len的字串
9.Index(S, T, pos)
初始条件：串S和T存在，T为非空串，1≦pos≦Strlength(S)
操作结果：若主串中存在和串T值相同的字串，则返回它在字串S中第pos个字符之后第一次出现的位置；否则函数值为0
10.Replace(&S, T, V)
初始条件：串S，T和V存在，T是非空串
操作结果：用V替换主串S中出现的所有与T相等的不重叠的字串
11.StrInsert(&S, pos, T)
初始条件：串S和T存在，1≦pos≦Strlength(S)+1
操作结果：在串S的第pos个位置字符之前传入串T
12.StrDelete(&S, pos, len)
初始条件：串S存在，1≦pos≦Strlength(S)-len+1
操作结果：从串S中删除第pos个字符起长度为len的字串
13.DestroyString(&S)
初始条件：串S存在
操作结果：串S被销毁
14.PrintString(T)
初始条件：串S存在
操作结果：将S打印在屏幕上
15.InitString(&T)
初始条件：串T已经定义
操作结果：将串S初始化
==========================================================================================
备注：
1.这里将空串定义为：T.ch = new char[1]; T.length = 0; *T.ch = '\0';
2.这里将不存在的串视为：T.ch = NULL;
3.字符串全部以'\0'结束
4.尽量保持各个函数的独立性，只有在Replace()函数中调用了Index()函数
5.函数中的打印信息可以根据需要选择
6.由于函数比较多，此处不再提供详细的测试代码，可以根据需要自行设计测试特定函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    char *ch;
    int length;
}HString;

//1.StrAssign(&T, chars)
int StrAssign(HString *T, char *chars)
{
   /*生成一个其值等于串常量chars的串T*/

   /*定义局部变量*/
   char *c;
   int i,j;
   /*对串是否为空进行判断*/
   if(T->ch) {
      printf("原串不为空\n");
   }

   /*求chars的长度*/
   for(i = 0,c = chars;*c;++i,++c);
   /*进行判断*/
   if(!i) {// chars为空
      T->ch = NULL;
      T->length = 0;
   }else {// chars不为空，为其分配空间
      if(!(T->ch = (char *) malloc(i * sizeof(char)))) {
         exit(0);
      }
      for(j = 0;j < i;j++) {
         T->ch = chars[j];
      }
      //T->ch[0..i -1] = chars[0..i - 1];// 将chars的内容依次赋值给串
      T->length = i;
   }

   /*打印出T的长度length*/
   printf("StrAssign得到的串的长度: %d\n",T->length);

   return 0;
}

//3.PrintString(T)
int PrintString(HString *T)
{
   // 定义局部变量
   int i = 0;
   if(!T->ch) {
      printf("串不存在\n");
      exit(0);
   }else {
      printf("串的长度为: %d\n",T->length);
      while(i < T->length) {
         //printf("%d",i);
         printf("%c",T->ch++);
         //printf("Hello World");
         ++i;
      }

      printf("\n");
      return 0;
   }

   return 0;
}


//15.InitString(&T)
int InitString(HString *T)
{
    T->ch = NULL;
    T->length = 0;
    return 0;
}

//StrLength
int StrLength(HString T) {
   printf("HString's length: %d\n",T.length);

   return 0;
}

// StrCompare
int StrCompare(HString S,HString T) {
   // 定义局部变量
   int i;
   
   for(i = 0;i < S.length && i < T.length;i++) {
      // printf("差:n");
     
      if(S.ch[i] != T.ch[i]) {
         printf("差:n");
         //printf("S->ch[i] - T->ch[i]: %d\n",S->ch[i] - T->ch[i]);
      }

   }
   

   //printf("S->length - T->length: %d\n",S->length - T->length);
   
}
int main()
{
    HString T,S;

    char *test1 = "aaa";
    char *test2 = "aaa";

    StrAssign(&T,test1);
    StrAssign(&S,test2);
    //StrAssign(&S,test2);

    //StrLength(&T);
    PrintString(&T);
    // StrLength
    StrLength(T);
    // StrCompare
    //StrCompare(T,S);

    return 0;
}
