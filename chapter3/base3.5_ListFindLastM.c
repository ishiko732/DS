#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */
#include "../chapter2/ListOp.c"

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find( List L, int m ){
    PtrToNode p,q;
    p=L;
    q=L;
    int i=0;
    while(q&&(i++)<m){
        q=q->Next;
    }
    if(!q){
        return ERROR;
    }
    while(q){
        p=p->Next;
        q=q->Next;
    }
    return p->Data;
}