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
  
typedef struct  
{  
    char *ch;  
    int length;  
}HString;  
  
//1.StrAssign(&T, chars)  
int StrAssign(HString *T, char *chars)  
{  
    if (T->ch)  
    {  
        printf("线性表不为空");  
    }  
  
    char *ctemp = chars;  
    T->length = 0;  

    while(*ctemp)  
    {  
        ++T->length;  
        ++ctemp;  
    }  
  
    T->ch = new char[T->length + 1];  
    if (!T->ch)  
    {  
        printf("StrAssign()函数执行，内存分配失败，程序即退出\n");  
        system("pause");  
        exit(-1);  
    }  
  
    char *tmp = T->ch;  
    while(*chars)  
    {  
        *tmp++ = *chars++;  
    }  
    *tmp = '\0';  
  
    printf("StrAssign()函数执行，串T生成成功\n");  
    return 0;  
}

//14.PrintString(T)  
int PrintString(HString *T)  
{  
    if (!T->ch)  
    {  
        printf("PrintString()函数执行，串不存在\n");  
        return 1;  
    }  
    else  
    {  
        printf("PrintString()函数执行，串的长度为 %d ，打印结果如下：", T.length);  
        while(*T->ch)  
        {  
            printf("%c", *T->ch++);  
        }  
        printf("\n");  
        return 0;  
    }  
}  


//15.InitString(&T)  
int InitString(HString *T)  
{  
    T->ch = NULL;  
    T->length = 0;  
    return 0;  
}  
  
int main()  
{  
    HString T, T1, T2;  
    InitString(&T);  
    InitString(&T1);  
    InitString(&T2);  
  
    char *test = "abc abc abc abc a";  
    char *test1 = "a";  
    char *test2 = "/Here/";  
  
    StrAssign(&T, test);  
    PrintString(&T);  
  
    StrAssign(&T1, test1);  
    PrintString(T1);  
  
    StrAssign(&T2, test2);  
    PrintString(&T2);  

    system("pause");  
    return 0;  
}  
