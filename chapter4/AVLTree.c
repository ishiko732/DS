#include <stdio.h>
#include <stdlib.h>
typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef int ElementType;
struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(AVLTree T)
{
    if (T)
    {
        int L = GetHeight(T->Left);
        int R = GetHeight(T->Right);
        int max = (L > R ? L : R);
        return max + 1;
    }
    return 0;
}

AVLTree SingleLeftRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);

AVLTree Insert(AVLTree T, ElementType X)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        T->Height = 1;
    }
    else if (T->Data > X)
    {
        T->Left = Insert(T->Left, X);
        int d = GetHeight(T->Left) - GetHeight(T->Right);
        if (d == 2)
        { // 插入在左子树上,高度变化为正数
            if (T->Left->Data > X)
            {
                T = SingleLeftRotation(T);
            }
            else
            {
                T = DoubleLeftRightRotation(T);
            }
        }
    }
    else if (T->Data < X)
    {
        T->Right = Insert(T->Right, X);
        int d = GetHeight(T->Left) - GetHeight(T->Right);
        if (d == -2)
        { // 插入在右子树上,高度变化为负数
            if(T->Right->Data <X){
                T=SingleRightRotation(T);
            }else{
                T=DoubleRightLeftRotation(T);
            }
        }
    }
    else if(X==T->Data){
        // 无须插入
    }

    T->Height=Max(GetHeight(T->Left),GetHeight(T->Right))+1;
    return T;
}

AVLTree SingleLeftRotation(AVLTree A){
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left),GetHeight(B->Right))+1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A){
    AVLTree B=A->Right;
    A->Right=B->Left;
    B->Left=A;
    A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left),GetHeight(B->Right))+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A){
    A->Left=SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A){
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}