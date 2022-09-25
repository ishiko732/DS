#include "Sort.h"

#ifndef List
typedef struct LNode* PtrToNode;
struct LNode{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
#endif
#define M 101
//如果已知N个关键字的取值范围在$[0,M-1]$之间,而M比N小得多
//则桶排序算法将为关键字的每一个可能取值建立一个桶,即M个桶
#ifndef print
void print(PtrToNode Node){
    PtrToNode p=Node->Next;
    while (p){
        printf("%d\b",p->Data);
        p=p->Next;
    }
}
#endif
void BucketSort(ElementType A[],int N){
    int i;
    List* count=(List*)malloc(M*sizeof(struct LNode));
    PtrToNode cell;
    for(i=0;i<M;i++){
        count[i]->Next=NULL;
    }
    for(i=0;i<N;i++){
        cell =malloc(sizeof(struct LNode));
        cell->Data=A[i];
        cell->Next=count[A[i]]->Next;
        count[A[i]]->Next=cell;
    }
    for(i=0;i<M;i++){
        if(count[i]->Next){
            print(count[i]);
        }
    }
}