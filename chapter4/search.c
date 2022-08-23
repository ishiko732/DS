#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
#define MAXSIZE 10
#define NotFound 0
#define ERROR -1
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
typedef int Position;

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position SequentialSearch(List L,ElementType K);
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput(){
    List L=(List)malloc(sizeof(struct LNode));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",L->Data+i);
    }
    L->Last=n;
    return L;
}

Position SequentialSearch(List L,ElementType K){
    Position i;
    L->Data[0]=K;
    for(i=L->Last;L->Data[i]!=K;i--);
    return i;
}

Position BinarySearch(List L,ElementType K){
    Position left,right,mid;
    left =1 ;
    right = L->Last;
    while(left<=right){
        mid= (left+right)/2;
        if(L->Data[mid]>K){
            right = mid-1;
        }else if(L->Data[mid]<K){
            left = mid+1;
        }else if(L->Data[mid]==K){
            return mid;
        }
    }
    return NotFound;
}