#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef enum{false,true} bool;
typedef int ElementType;
typedef struct SNode* PtrToSNode;
struct SNode{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack(){
    Stack S;
    S=malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}

bool IsEmpty(Stack s){
    return s->Next==NULL;
}

bool Push(Stack S,ElementType X){
    PtrToSNode cell;
    cell=malloc(sizeof(struct SNode));
    cell->Data=X;

    cell->Next=S->Next;
    S->Next=cell;
    return true;
}

ElementType Pop(Stack S){
    PtrToSNode cell;
    ElementType top;
    if(IsEmpty(S)){
        printf("stack is empty");
        return ERROR;
    }
    cell=S->Next;
    S->Next=cell->Next;
    top =cell->Data;
    free(cell);
    return top;
}

