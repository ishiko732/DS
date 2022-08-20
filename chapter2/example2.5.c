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
#include "ListOp.c"
List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
// 应直接使用原序列中的结点，返回归并后的带头结点的链表头指针


List Merge(List L1, List L2){
    List L3,rear;
    L3=(List)malloc(sizeof(struct Node));
    L3->Next=NULL;
    rear=L3;
    while(L1->Next&&L2->Next){
        if(L1->Next->Data<L2->Next->Data){
            rear->Next=L1->Next;
            L1->Next=L1->Next->Next;
            rear=rear->Next;
            rear->Next=NULL;
        }else{
            rear->Next=L2->Next;
            L2->Next=L2->Next->Next;
            rear=rear->Next;
            rear->Next=NULL;
        }
    }
    if(L1->Next){
        rear->Next=L1->Next;
        L1->Next=NULL;
    }
    if(L2->Next){
        rear->Next=L2->Next;
        L2->Next=NULL;
    }
    return L3;
}