#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Create(ElementType e);
#include "ListOp.c"
List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Create(ElementType e)
{
    List L = (List)malloc(sizeof(struct Node));
    L->Data = e;
    L->Next = NULL;
    return L;
}
List Insert(List L, ElementType X)
{
    List p = L, pre = NULL, cell;
    while (p && p->Data < X)
    {
        pre = p;
        p = p->Next;
    }
    cell = Create(X);
    if (pre == NULL)
    { // 头插入
        cell->Next = L->Next;
        L->Next = cell;
    }
    else
    {
        cell->Next=pre->Next;
        pre->Next=cell;
    }
    return L;
}

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/*
input
5
1 2 4 5 6
3
output:
1 2 3 4 5 6
*/
/* 你的代码将被嵌在这里 */
