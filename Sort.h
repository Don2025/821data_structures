#ifndef INC_821DATA_STRUCTURES_SORT_H
#define INC_821DATA_STRUCTURES_SORT_H

typedef int ElementType;
typedef  struct ForSort
{
    ElementType key;
}ForSort;

void InitForSort(ForSort *FS,int a)
{
    FS->key = a;
}

#endif //INC_821DATA_STRUCTURES_SORT_H
