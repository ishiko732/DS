#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

List ReadInput(){
    List l=(List)malloc(sizeof(struct LNode));
    int n;
    scanf("%d",&n);
    l->Last=n-1;
    for (int i=0;i<(MAXSIZE)&&i<n;i++){
        scanf("%d",&(l->Data[i]));
    }
    return l;
}
void PrintList(List L){
    printf("%d",L->Data[0]);
    for(int i=1;i<L->Last;i++){
        printf(" %d",L->Data[i]);
    }
    printf("\nLast = %d\n",L->Last);
}
/* 你的代码将被嵌在这里 */
bool insertElement(List L,Position index,ElementType X){
    if(L->Last==MAXSIZE-1){
        return false;
    }
    if(L->Last==index){
        L->Data[++(L->Last)]=X;
        return true;
    }
    for(int i=L->Last;i>=index;i--){
        L->Data[i+1]=L->Data[i];
    }
    L->Data[index]=X;
    L->Last+=1;
    return true;
}

// bool Insert( List L, ElementType X ){ // 方法1
//     for(int i=L->Last;i>=0;i--){
//         if(L->Data[i]==X){
//             return false;
//         }else if (L->Data[i]>X){
//             return insertElement(L,i+1,X);
//         }else if(i==0){
//             return insertElement(L,0,X);
//         }
//     }
//     return false;
// }

bool Insert( List L, ElementType X ){ // 方法2
    int left,right,mid;
    left = 0;
    right =L->Last;
    while(left<=right){
        mid=(left+right)/2;
        if(L->Data[mid]==X){
            return false;
        }else if(L->Data[mid]<X){
            right = mid - 1;
        }else if(L->Data[mid]>X){
            left = mid +1;
        }
    }
    return insertElement(L,left,X);
}

/*
5
35 12 8 7 3
10
*/

/*
6
35 12 10 8 7 3
8
*/