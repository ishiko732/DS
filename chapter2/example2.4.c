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
    List pre=L,cell=Create(X);
    while(pre->Next){
        if(pre->Next->Data>X){
            break;
        }else{
            pre=pre->Next;
        }
    }
    cell->Next=pre->Next;
    pre->Next=cell;
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
