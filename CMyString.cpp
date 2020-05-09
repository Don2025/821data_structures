#include <stdio.h>
#include <stdlib.h>
#include <string.h> //C的标准库
#include "CMyString.h"
//串运算的实现文件CMyString.c 我这里直接用的cpp但是不调用cpp的标准库

void InitCMyString(CMyString *CS,char *s)  //初始化函数，构造一个字符指针所指的串
{
    char *p1, *p2;
    for (CS->length = 0, p1=CS->str, p2=(char *)s; *p2; CS->length++)
        *p1++ = *p2++;
    *p1 = 0;
}

void Concatenate(CMyString *CS,CMyString *s)  //将字符串s附加到本字符串之后
{
    if(CS->length+s->length<=MAX_STRING_SIZE)
    {
        memcpy(CS->str+CS->length, s->str, s->length+1);
        CS->length += s->length;
    }
    else printf("error: string length overflow!\n");
}

void InsertS(CMyString *CS,int pos,CMyString *s)  //将字符串s插入到本字符串pos所指向的位置
{
    if(CS->length+s->length<=MAX_STRING_SIZE)
    {
        memcpy(CS->str+pos+s->length,CS->str+pos,CS->length-pos+1);
        memcpy(CS->str+pos,s->str,s->length);
        CS->length += s->length;
    }
    else printf("error: string length overflow!\n");
}

void DeleteS(CMyString *CS,int pos,int len)  //删除从pos位置起的连续len个字符
{
    int rlen = len;
    if(pos+rlen > CS->length)
        rlen = CS->length-pos;
    CS->length -= rlen;
    memcpy(CS->str+pos,CS->str+pos+rlen,CS->length-pos+1);
}

CMyString SubString(CMyString *CS,const int pos,const int len)  //提取一个从pos位置起长度为len的子串
{
    int rlen = len;
    CMyString *tmpStr = (CMyString *)malloc(sizeof(CMyString));
    InitCMyString(tmpStr,(char *)" ");
    if(pos+len > CS->length)
        rlen = CS->length-pos;
    memcpy(tmpStr->str,CS->str+pos,rlen);
    tmpStr->length = rlen;
    tmpStr->str[tmpStr->length] = 0;
    return *tmpStr;
}

char * GetS(CMyString *CS)  //获取本字符串
{
    char *tmpStr = (char *)malloc(sizeof(char)*(CS->length+1));
    memcpy(tmpStr,CS->str,CS->length+1);
    return tmpStr;
}

void GenKMPNext(int *next,CMyString *s)  //计算next数组
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < s->length-1)
    {
        //找出p0,p1,...,pi中最大的相同的最左端子串和最右端子串
        while(j>=0 && s->str[i]!=s->str[j])
            j = next[j];
        i++;
        j++;
        if(s->str[i]==s->str[j])
            next[i] = next[j];
        else next[i] = j;
    }
}

int Find(CMyString *CS,CMyString *s)  //在本字符串中查找字符串s首次出现的位置，如果不包含s则返回0
{
    int i,j,*next = (int *)malloc(sizeof(int)*s->length);
    //构造模式s的next数组，详见求next数组的算法
    GenKMPNext(next,s);
    for(i = 0, j = 0; i<s->length && j<CS->length; )
    {
        if(s->str[i]==CS->str[j])
        {
            i++;
            j++;
        }
        else if(next[i]>=0)
            i = next[i];
        else
        {
            i = 0;
            j++;
        }
    }
    if(i >= s->length)
        return j-(s->length);  //匹配成功，返回子串的起始位置
    else
        return -1;  //匹配失败，返回-1
}

void StringTestMain()
{
    CMyString *CS = (CMyString *)malloc(sizeof(CMyString));
    InitCMyString(CS,(char*)"hello");
    printf("After initCMyString, the string is:%s\n",GetS(CS));
    CMyString *tmp = (CMyString *)malloc(sizeof(CMyString));
    InitCMyString(tmp,(char*)"World.");
    Concatenate(CS,tmp);
    printf("After concatenate, the string is:%s\n",GetS(CS));
    InitCMyString(tmp,(char*)"NUDT.");
    InsertS(CS,5,tmp);
    printf("After inserting to the pos 5, the string is:%s\n",GetS(CS));
    DeleteS(CS,10,6);
    printf("After deleting the substring(pos:10,len:6),the string is:%s\n",GetS(CS));
    *tmp = SubString(CS,5,4);
    printf("The substring(pos:5,len:4) is:%s\n",GetS(tmp));
    InitCMyString(tmp,(char*)"NUDT");
    printf("The First occurrence of string NUDT is the pos %d\n",Find(CS,tmp));
}