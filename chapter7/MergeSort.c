#include "Sort.h"
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd);
void Msort(ElementType A[],ElementType TmpA[],int L,int RightEnd);

void MergeSort(ElementType A[],int N){
    ElementType *TmpA;
    TmpA=(ElementType *) malloc(N*sizeof(ElementType));
    //开辟一个与N*ElementType大小的空间,避免在Merge大量malloc和free
    if(TmpA!=NULL){
        Msort(A,TmpA,0,N-1);
        free(TmpA);
    }else{
        printf("空间不足\n");
    }
}

void Msort(ElementType A[],ElementType TmpA[],int L,int RightEnd){
    int Center;
    if(L<RightEnd){
        Center=(L+RightEnd)/2;
        Msort(A,TmpA,L,Center);
        Msort(A,TmpA,Center+1,RightEnd);
        Merge(A,TmpA,L,Center+1,RightEnd);
    }
}

void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd,NumElements,Tmp;
    LeftEnd=R-1;
    Tmp=L;
    NumElements=RightEnd-L+1;

    while(L<=LeftEnd&&R<=RightEnd){
        if(A[L]<=A[R]){
            TmpA[Tmp++]=A[L++];
        }else{
            TmpA[Tmp++]=A[R++];
        }
    }
    while(L<=LeftEnd){
        TmpA[Tmp++]=A[L++];
    }
    while(R<=RightEnd){
        TmpA[Tmp++]=A[R++];
    }
    for(int i=0;i<NumElements;i++,RightEnd--){//将有序的TmpA复制回到A
        A[RightEnd]=TmpA[RightEnd];
    }
}

void Merge1(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd);
void Merge_pass(ElementType A[],ElementType TmpA[],int N,int length);
void MergeSort_pass(ElementType A[],int N){
    ElementType *TmpA;
    TmpA=(ElementType *) malloc(N*sizeof(ElementType));
    //开辟一个与N*ElementType大小的空间,避免在Merge大量malloc和free
    int length=1;
    if(TmpA!=NULL){
        while(length<N){
            Merge_pass(A,TmpA,N,length);
            length*=2;
            Merge_pass(TmpA,A,N,length);
            length*=2;
        }
        free(TmpA);
    }else{
        printf("空间不足\n");
    }
}

void Merge_pass(ElementType A[],ElementType TmpA[],int N,int length){
    int i;
    for(i=0;i<N-2*length;i+=2*length){
        Merge1(A,TmpA,i,i+length,i+2*length-1);
    }
    if(i+length<N){
        Merge1(A,TmpA,i,i+length,N-1);
    }else{//只剩下一个序列时
        for(int j=i;j<N;j++){
            TmpA[j]=A[j];
        }
    }
}

void Merge1(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd,NumElements,Tmp;
    LeftEnd=R-1;
    Tmp=L;
    NumElements=RightEnd-L+1;

    while(L<=LeftEnd&&R<=RightEnd){
        if(A[L]<=A[R]){
            TmpA[Tmp++]=A[L++];
        }else{
            TmpA[Tmp++]=A[R++];
        }
    }
    while(L<=LeftEnd){
        TmpA[Tmp++]=A[L++];
    }
    while(R<=RightEnd){
        TmpA[Tmp++]=A[R++];
    }
}