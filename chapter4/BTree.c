#include <stdio.h>
#include <stdlib.h>
typedef struct TNode *Position;
typedef Position BinTree;
typedef char ElementType;
typedef Position BinTree;
// =====stack&queue====
typedef enum
{
    false,
    true
} bool;
#define ERROR -1
#define MAXSIZE 100
#include "Stack_op.c"
#include "Queue_op.c"
// =====stack&queue====
#define NoInfo '0'
struct TNode
{
    /* data */
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT)
{ // 前序遍历(递归)
    if (BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PreorderTraversal_Stack(BinTree BT)
{ // 前序遍历(堆栈)
    Stack S = CreateStack();
    BinTree T = BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            printf(" %c", T->Data);
            T = T->Left;
        }
        T = Pop(S);
        T = T->Right;
    }
}

void InorderTraversal(BinTree BT)
{ // 中序遍历(递归)
    if (BT)
    {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void InorderTraversal_Stack(BinTree BT)
{ // 中序遍历(堆栈)
    Stack S = CreateStack();
    BinTree T = BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            T = T->Left;
        }
        T = Pop(S);
        printf(" %c", T->Data);
        T = T->Right;
    }
}

void PostorderTraversal(BinTree BT)
{ // 后序遍历(递归)
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}

void PostorderTraversal_Stack(BinTree BT)
{ // 后序遍历(堆栈)
    Stack S = CreateStack();
    Stack res = CreateStack();
    BinTree T = BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            Push(res, T);
            T = T->Right;
        }
        T = Pop(S);
        T = T->Left;
    }
    while (!IsEmpty(res))
    {
        T = Pop(res);
        printf(" %c", T->Data);
    }
}

void LevelorderTraversal_Queue(BinTree BT) // 队列实现层序遍历
{                                          // 层序遍历
    Queue Q;
    BinTree T;
    if (!BT)
        return;

    Q = CreateQueue(MAXSIZE);
    AddQ(Q, BT);
    while (!isEmpty(Q))
    {
        T = DeleteQ(Q);
        printf(" %c", T->Data);
        if (T->Left)
            AddQ(Q, T->Left);
        if (T->Right)
            AddQ(Q, T->Right);
    }
}

void LevelorderTraversal(BinTree BT)
{ // 层序遍历

    BinTree T,Q[MAXSIZE];
    if (!BT)
        return;
    int front=0,rear=0;

    Q[rear++%MAXSIZE]=BT;
    while (front<rear)
    {
        T = Q[front++%MAXSIZE];
        printf(" %c", T->Data);
        if (T->Left)
            Q[rear++%MAXSIZE]=T->Left;
        if (T->Right)
            Q[rear++%MAXSIZE]=T->Right;
    }
}

BinTree CreatBinTree()
{
    ElementType Data;
    BinTree BT, T;
    Queue Q = CreateQueue(MAXSIZE);
    scanf("%c", &Data);
    if (Data != NoInfo)
    {
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);
    }
    else
    {
        return NULL;
    }
    while (!isEmpty(Q))
    {
        T = DeleteQ(Q);
        scanf("%c", &Data);
        if (Data == NoInfo || Data == '\n')
            T->Left = NULL;
        else
        {
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%c", &Data);
        if (Data == NoInfo || Data == '\n')
            T->Right = NULL;
        else
        {
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    }
    return BT;
}

int main()
{
    BinTree BT = CreatBinTree(); // ABCDFGI00E00H000000
    printf("Inorder:");
    InorderTraversal_Stack(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal_Stack(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal_Stack(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
