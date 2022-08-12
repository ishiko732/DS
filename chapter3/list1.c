# include <stdio.h>
# include <stdlib.h>
#define MAXSIZE 5
#define ERROR -1
typedef enum bool{false,true} bool;
typedef int Position;
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

List MakeEmpty(){ // init
    List l=(List) malloc(sizeof(struct LNode));
    l->Last=-1;
    return l;
}

Position Find(List L,ElementType X){
    Position i=0;
    while(i<=L->Last&&L->Data[i]!=X){
        i++;
    }
    if(i>L->Last){
        return ERROR;
    }else{
        return i;
    }
}
/*
    (1+2+...+n) /n => O(n)

*/
bool Insert(List L,ElementType X,Position i){
    if(L->Last==MAXSIZE-1){
        printf("FULL");
        return false;
    }
    if(i<0 ||i>L->Last+1){
        printf("ILLEGAL POSITION");
        return false;
    }
    for(Position j=L->Last+1;j>=i;j--){
        L->Data[j]=L->Data[j-1];
    }
    L->Data[i]=X;
    L->Last++;
    return true;
}

bool Delete(List L,Position i){
    Position j;
    if(i<0 || i>L->Last){
        printf("POSITION %d EMPTY",i);
        return false;
    }
    for(j=i;j<=L->Last;j++){
        L->Data[j-1]=L->Data[j];
    }
    L->Last--;
    return true;
}

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
