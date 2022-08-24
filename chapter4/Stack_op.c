#include <stdio.h>
#include <stdlib.h>
typedef struct SNode* PtrToSNode;
typedef BinTree TreeType;
struct SNode{
    TreeType Data;
    PtrToSNode Next;
};

typedef PtrToSNode Stack;
Stack CreateStack(){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->Next=NULL;
    s->Data=ERROR;
    return s;
}

bool Push(Stack s,TreeType X){
    PtrToSNode cell =(PtrToSNode)malloc(sizeof(struct SNode));
    cell->Data=X;
    cell->Next=s->Next;
    s->Next=cell;
    return true;
}

bool IsEmpty(Stack s){
    return s->Next==NULL;
}

TreeType Pop(Stack s){
    TreeType data;
    if(IsEmpty(s)){
        printf("Stack is empty");
        return ERROR;
    }else{
        PtrToSNode cell=s->Next;
        s->Next=cell->Next;
        data=cell->Data;
        free(cell);
        return data;
    }
}