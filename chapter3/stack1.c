#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
typedef enum{false,true} bool;
typedef int Position;
typedef int ElementType;
typedef struct SNode* PtrToSNode;
struct SNode{
    ElementType* Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;
Stack CreateStack(int MaxSize){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    s->MaxSize=MaxSize;
    s->Top=-1;
    return s;
}

bool IsFull(Stack s){
    return s->Top==s->MaxSize-1;
}
bool Push(Stack s,ElementType X){
    if(IsFull(s)){
        printf("Stack is full");
        return false;
    }else{
        s->Data[++(s->Top)]=X;
        return true;
    }
}

bool IsEmpty(Stack s){
    return s->Top==-1;
}

ElementType Pop(Stack s){
    if(IsEmpty(s)){
        printf("Stack is empty");
        return ERROR;
    }else{
        return s->Data[(s->Top)--];
    }
}