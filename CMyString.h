#ifndef INC_821DATA_STRUCTURES_CMYSTRING_H
#define INC_821DATA_STRUCTURES_CMYSTRING_H
#define MAX_STRING_SIZE 1024

typedef struct CMyString
{
    int length;  //串的实际长度
    //字符串存储空间，包括一个附加的结束字符的存储空间
    char str[MAX_STRING_SIZE+1];
}CMyString;

void InitCMyString(CMyString *,char *s);  //初始化函数，构造一个字符指针所指的串
void Concatenate(CMyString *,CMyString *s);  //将字符串s附加到本字符串之后
void InsertS(CMyString *,int pos,CMyString *s);  //将字符串s插入到本字符串pos所指向的位置
void DeleteS(CMyString *,int pos,int len);  //删除从pos位置起的连续len个字符
CMyString SubString(CMyString *,const int pos,const int len);  //提取一个从pos位置起长度为len的子串
char *GetS(CMyString *);  //获取本字符串
void GenKMPNext(int *next,CMyString *s); //计算next数组
int Find(CMyString *,CMyString *s);  //在本字符串中查找字符串s首次出现的位置，如果不包含s则返回0
void StringTestMain(void);

#endif //INC_821DATA_STRUCTURES_CMYSTRING_H
