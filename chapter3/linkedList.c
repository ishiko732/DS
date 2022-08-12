#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
// 不带头结点的单链表
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int Length(List L){
    Position p;
    int cnt=0;
    p=L;
    while(p){
        p=p->Next;
        cnt++;
    }
    return cnt;
}

Position Find(List L,ElementType X){
    Position p=L;
    while(p&&p->Data!=X){
        p=p->Next;
    }
    return p;
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

List Insert(List L,ElementType X,Position P){
    Position tmp,pre;
    tmp =(List) malloc(sizeof(struct LNode));
    tmp ->Data =X;
    tmp ->Next =NULL;

    if(L==P){ // 头插入(位序)
        tmp->Next=L;
        return tmp;
    }else{
        pre=_FindPre(L,P);
        if(pre==NULL){
            printf("Wrong Position for Insertion\n");
            free(tmp);
            return ERROR;
        }else{
            tmp->Next=pre->Next;
            pre->Next=tmp;
            return L;
        }
    }
}

List Delete( List L, Position P ){
    Position p,tmp;
    if(L==P){
        p=L;
        tmp = p;
        p=p->Next;
        free(tmp);
        return p;
    }else{
        p=_FindPre(L,P);
        if(p==ERROR){
            printf("Wrong Position for Deletion\n");
            return ERROR;
        }else{
            tmp = p->Next;
            p->Next=tmp->Next;
            free(tmp);
            return L;
        }
    }
}