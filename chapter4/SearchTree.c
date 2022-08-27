#include <stdio.h>
#include <stdlib.h>
typedef struct TNode *Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

Position Find_recursion(BinTree BST,ElementType X);
Position Find(BinTree BST,ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
Position Insert(BinTree BST,ElementType X);
BinTree Delete(BinTree BST,ElementType X);

Position Find_recursion(BinTree BST,ElementType X){
    if(!BST){
        return NULL;
    }
    if(BST->Data>X){
        Find_recursion(BST->Left,X);
    }else if(BST->Data<X){
        Find_recursion(BST->Right,X);
    }else {
        return BST;
    }
}
Position Find(BinTree BST,ElementType X){
    while(BST){
        if(BST->Data>X){
            BST=BST->Left;
        }else if(BST->Data<X){
            BST=BST->Right;
        }else{
            break;
        }
    }
    return BST;
}

Position FindMin(BinTree BST){
    if(BST){
        while(BST->Left){
            BST=BST->Left;
        }
    }
    return BST;
}
Position FindMax(BinTree BST){
    if(BST){
        while(BST->Right){
            BST=BST->Right;
        }
    }
    return BST;
}

Position Insert(BinTree BST,ElementType X){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }else{
        if(BST->Data>X){
            BST->Left=Insert(BST->Left,X);
        }else if(BST->Data<X){
            BST->Right=Insert(BST->Right,X);
        }else{
            // X 已经存在
        }
    }
    return BST;
}

BinTree Delete(BinTree BST,ElementType X){
    Position tmp;
    if(!BST){
        printf("Not Found\n");
    }else{
        if(BST->Data>X){
            BST->Left=Delete(BST->Left,X);
        }else if(BST->Data<X){
            BST->Right=Delete(BST->Right,X);
        }else{
            if(BST->Left&&BST->Right){
                tmp=FindMin(BST->Right);
                BST->Data=tmp->Data;
                BST->Right=Delete(BST->Right,BST->Data);
            }else{
                tmp=BST;
                if(!BST->Left){
                    BST=BST->Right;
                }else{
                    BST=BST->Left;
                }
                free(tmp);
            }
        }
    }
    return BST;
}


void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal( BinTree BT ){
    if(BT){
        PreorderTraversal(BT->Left);
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Right);
    }
}

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */