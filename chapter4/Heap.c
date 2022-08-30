#include <stdio.h>
#include <stdlib.h>
typedef struct HNode* Heap;
typedef int ElementType;
struct HNode{
    ElementType* Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MAXDATA 1000
typedef enum{false,true} bool;

MaxHeap CreateHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool Insert(MaxHeap H,ElementType X);
bool IsEmpty(MaxHeap H);
ElementType DeleteMax(MaxHeap H);

MaxHeap CreateHeap(int MaxSize){
    MaxHeap H= (MaxHeap)malloc(sizeof(struct HNode));
    H->Data =(ElementType *) malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

bool IsFull(MaxHeap H){
    return H->Size==H->Capacity;
}

bool Insert(MaxHeap H,ElementType X){
    if(IsFull(H)){
        printf("heap is full\n");
        return false;
    }
    int i=++H->Size;
    for(;H->Data[i/2]<X;i/=2){
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}