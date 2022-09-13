#include <stdio.h>
#include <stdlib.h>
#ifndef bool
typedef enum {false,true} bool;
#endif
#ifndef ElementType
typedef int ElementType;
#endif
#ifndef MAXSIZE
#define MAXSIZE 100
#endif

typedef struct QNode* PtrToQNode;
struct QNode{
    ElementType* Data;
    int Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize){
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front= 0;
    Q->Rear = 0;
    Q->MaxSize=MaxSize;
    return Q;
}

bool isFull(Queue Q){
    return (Q->Rear+1)%Q->MaxSize==Q->Front;
}
bool isEmpty(Queue Q){
    return Q->Rear==Q->Front;
}

bool AddQ(Queue Q,ElementType X){
    if(isFull(Q)){
        printf("Queue Full\n");
        return false;
    }else{
        Q->Rear=(Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear]=X;
        return true;
    }
}

ElementType DeleteQ(Queue Q){
    if(isEmpty(Q)){
        printf("Queue Empty\n");
        return false;
    }else{
        Q->Front=(Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];
    }
}