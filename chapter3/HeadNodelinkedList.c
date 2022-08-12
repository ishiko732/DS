#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty(){
    List h=(List) malloc(sizeof(struct LNode));
    h->Data=-1;
    h->Next=NULL;
    return h;
}
Position Find( List L, ElementType X ){
    Position p;
    p=L->Next;
    while(p&&p->Data!=X){
        p=p->Next;
    }
    if(p==NULL){
        return ERROR;
    }else{
        return p;
    }
}

Position _FindPre(List L,Position P){
    Position p=L;
    while(p&&p->Next!=P){
        p=p->Next;
    }
    if(p==NULL){
        return ERROR;
    }else{
        return p;
    }
} 
bool Insert( List L, ElementType X, Position P ){
    Position pre,tmp;
    pre=_FindPre(L,P);
    if(pre==ERROR){
        printf("Wrong Position for Insertion\n");
        return false;
    }else{
        tmp=(Position)malloc(sizeof(struct LNode));
        tmp->Data=X;

        tmp->Next=pre->Next;
        pre->Next=tmp;
        return true;
    }

}
bool Delete( List L, Position P ){
    Position pre,tmp;
    pre=_FindPre(L,P);
    if(pre==ERROR){
        printf("Wrong Position for Deletion\n");
        return false;
    }else{
        tmp = pre->Next;
        pre->Next=tmp->Next;
        free(tmp);
        return true;
    }
}
