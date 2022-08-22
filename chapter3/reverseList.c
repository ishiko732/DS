#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read_NoHead(); /* 细节在此不表 */
void Print_NotHead( List L );//不带头结点
#include "../chapter2/ListOp.c"

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read_NoHead();
    L2 = Reverse(L1);
    Print_NotHead(L1);
    Print_NotHead(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
/*
input
5
1 3 4 5 2
output
1
2 5 4 3 1
*/

List Reverse( List L ) {
    List prev = NULL;
    List current = L;
    List tmp;
    while (current) {
        tmp = current->Next;
        current->Next = prev;
        prev = current;
        current = tmp;
    }
    
    return prev;
}